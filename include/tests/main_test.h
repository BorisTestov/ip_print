#pragma once
#include "version.h"
#include <QtTest/QtTest>

class TestMain : public QObject {
  Q_OBJECT
private slots:
  void TestVersion();
  void TestPrint();
};

QTEST_MAIN(TestMain)
