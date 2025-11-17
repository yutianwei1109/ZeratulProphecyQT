#ifndef PROGRAMTEST_H
#define PROGRAMTEST_H

#include <QObject>

#include <exception>

// 工具宏
#define TEST_CALL(expr, name)                              \
    do {                                                   \
        try {                                              \
            expr;                                          \
        } catch (const std::exception& e) {                \
            failed.push_back(std::string(name) +           \
                             " → exception: " + e.what()); \
        } catch (...) {                                    \
            failed.push_back(std::string(name) +           \
                             " → unknown exception");       \
        }                                                  \
    } while (0)

class programTest : public QObject
{
    Q_OBJECT
public:
    explicit programTest(QObject *parent = nullptr);

    void card_structTest();
    void userListModelTest();

};

#endif // PROGRAMTEST_H
