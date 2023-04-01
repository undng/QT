#include <QCoreApplication>
#include "QDebug"
static int c=0;
static int d=0;


class ca
{
private:
 int _a;
public:
 ca()
 {
     _a=4;
 }
 int geta()
 {
     return _a+c+d;
 }
 void seta(int a)
 {
     _a=a;
 }
 ~ca()
 {
     _a=1; c=2; d=3;
 }
};


class cb:public ca
{
private:
 int _b;
public:
 cb():ca()
 {
     _b=10;
 }
 int getb()
 {
     return _b+geta();
 }
 ~cb()
 {
     c=3;
 }
};


class cc
{
private:
 QSharedPointer<ca> _a;
public:
 cc(QSharedPointer<ca> a1)
 {
     _a = a1;
 }
 int getc()
 {
     return _a->geta()+c;
 }
};


int main(int argc, char *argv[])
{
 QCoreApplication a(argc, argv);
 QSharedPointer<ca> a2 = QSharedPointer<ca>(new ca());
 QSharedPointer<cb> b1 = QSharedPointer<cb>(new cb());
 if(true)
 {
 ca a1;
 qDebug()<<a1.geta()+c;
 }
 qDebug()<<b1->getb();
 cc c1(a2);
 a2->seta(9);
 b1.clear();
 qDebug()<<c1.getc();
 a2.clear();
 return a.exec();
}
