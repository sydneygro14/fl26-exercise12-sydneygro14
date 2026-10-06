#include <QtTest/QtTest>
#include <QtWidgets>
#include <QDebug>

#include "toggle_widget.h"

class TestToggleWidget : public QObject {
  Q_OBJECT

private slots:

  // Define tests here

  // checks the light starts off and flips on and off with each button click
  void testButtonToggle();
  
};

// Implement the tests here

void TestToggleWidget::testButtonToggle(){

  // creates the widget under test with its default starting state
  ToggleWidget w;

  // looks up the push button inside the widget since it is not exposed directly
  QPushButton * pb = w.findChild<QPushButton *>();

  // confirms the button was actually found before using it
  QVERIFY(pb != nullptr);

  // confirms the light starts in the off state before any clicks
  QVERIFY(!w.isOn());

  // simulates a left mouse click on the button
  QTest::mouseClick(pb, Qt::LeftButton);

  // confirms the first click turned the light on
  QVERIFY(w.isOn());

  // simulates a second click on the same button
  QTest::mouseClick(pb, Qt::LeftButton);

  // confirms the second click turned the light back off
  QVERIFY(!w.isOn());
}


QTEST_MAIN(TestToggleWidget)
#include "test_toggle_widget.moc"