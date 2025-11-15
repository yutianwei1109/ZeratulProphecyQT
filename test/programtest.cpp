#include "programtest.h"

#include <QDebug>
#include <QFile>
#include <QTextStream>

#include <iostream>
#include <string>
#include <vector>

#include "../src/common/card_struct.h"
#include "../src/model/userlistmodel.h"

programTest::programTest(QObject *parent) : QObject(parent)
{
    // card_structTest(); // 已测试
    userListModelTest();
}

void programTest::card_structTest() {
    std::vector<std::string> failed;

    // ------------------------------
    // 1. 测试构造函数
    // ------------------------------
    TEST_CALL(card_struct c0;, "default ctor");

    TEST_CALL(card_struct c1(1, 2, "Terran", "Marine", 3, 4),
              "ctor(id,int,string,string,int,int)");

    TEST_CALL(card_struct c2(1, 2, std::string("Terran"),
                             std::string("Marine"), 3, 4),
              "ctor(id,int,string&&,string&&,int,int)");

    TEST_CALL(card_struct c3("1-2-Terran-Marine-3-4"),
              "ctor(format)");

    TEST_CALL(card_struct::fromString("1-2-Terran-Marine-3-4"),
              "fromString");


    // ------------------------------
    // 2. 测试 getters
    // ------------------------------
    {
        card_struct c(1, 2, "Terran", "Marine", 3, 4);
        TEST_CALL(c.id(),       "id()");
        TEST_CALL(c.star(),     "star()");
        TEST_CALL(c.race(),     "race()");
        TEST_CALL(c.name(),     "name()");
        TEST_CALL(c.number(),   "number()");
        TEST_CALL(c.power(),    "power()");
        TEST_CALL(c.toString(), "toString()");
        TEST_CALL(std::string(c), "operator std::string()");
    }

    // ------------------------------
    // 3. 测试 operator==
    // ------------------------------
    {
        card_struct a(1, 2, "Terran", "A", 3, 4);
        card_struct b(1, 5, "Zerg", "B", 6, 7);
        TEST_CALL(bool t = (a == b); (void)t, "operator== (id==)");
    }
    {
        card_struct a(0, 2, "Terran", "A", 3, 4);
        card_struct b(0, 2, "Terran", "A", 3, 4);
        TEST_CALL(bool t = (a == b); (void)t, "operator== (custom)");
    }

    // ------------------------------
    // 4. 测试 setters（custom card：id=0 才允许）
    // ------------------------------
    {
        card_struct c(0, 2, "Terran", "Marine", 3, 4);
        TEST_CALL(c.setStar(3),   "setStar()");
        TEST_CALL(c.setRace("Zerg"), "setRace()");
        TEST_CALL(c.setName("Hydra"), "setName()");
        TEST_CALL(c.setNumber(10), "setNumber()");
        TEST_CALL(c.setPower(500), "setPower()");
    }

    // ------------------------------
    // 5. setters 对数据库卡应抛异常
    // ------------------------------
    {
        card_struct c(1, 2, "Terran", "Marine", 3, 4);
        TEST_CALL(
            try { c.setStar(3); failed.push_back("setStar() did NOT throw"); }
            catch(...) {},
            "setStar() throw check"
        );
    }


    // ------------------------------
    // 最终输出测试结果
    // ------------------------------
    std::cout << "\n==============================\n";
    std::cout << "       TEST RESULT\n";
    std::cout << "==============================\n";

    if (failed.empty()) {
        std::cout << "✔ All tests PASSED!\n";
    } else {
        std::cout << "✘ FAILED tests:\n";
        for (auto& f : failed) std::cout << "  - " << f << "\n";
        std::cout << "\nTotal Failed: " << failed.size() << "\n";
    }
}

void programTest::userListModelTest() {
    // 打开log文件
    QFile logFile("test_userListModel.log");
    if (!logFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qWarning() << "无法打开log文件";
        return;
    }
    QTextStream out(&logFile);

    // 创建一个 UserListModel 实例
    UserListModel model;

    // 创建测试数据
    card_struct card1(1,1,"Terran","<custom>",1,100);
    card_struct card2(2,2,"Protoss","<custom>",2,200);
    card_struct card3(3,3,"Zerg","<custom>",3,300);

    // 测试 appendCard
    out << "test appendCard: " << model.appendCard(card1) << "\n";
    out << "test appendCard: " << model.appendCard(card2) << "\n";
    out << "test appendCard: " << model.appendCard(card3) << "\n";

    // 测试 rowCount
    out << "test rowCount: " << model.rowCount() << "\n";

    // 测试 getCard
    out << "test getCard (index 0): " << model.getCard(0).toString().c_str() << "\n";
    out << "test getCard (index 1): " << model.getCard(1).toString().c_str() << "\n";

    // 测试 contains
    out << "test contains (card1): " << model.contains(card1) << "\n";
    out << "test contains (card2): " << model.contains(card2) << "\n";

    // 测试 removeCard - index
    out << "test removeCard (index 1): " << model.removeCard(1) << "\n";
    out << "test rowCount after removeCard: " << model.rowCount() << "\n";
    out << "test getCard after removeCard: " << model.getCard(1).toString().c_str() << "\n";

    // 测试 removeCard - card
    out << "test removeCard (card1): " << model.removeCard(card1) << "\n";
    out << "test rowCount after removeCard: " << model.rowCount() << "\n";
    out << "test getCard after removeCard: " << model.getCard(0).toString().c_str() << "\n";

    // 测试 clear
    model.clear();
    out << "test clear rowCount: " << model.rowCount() << "\n";

    logFile.close();
}
