#include "myglwidget.h"
#include "mypainter.h"

#include <QPainter>

MyGLWidget::MyGLWidget(QWidget *parent)
    :QOpenGLWidget(parent)
{
    mypainter = new MyPainter;
}
/*
void MyGLWidget::redraw()
{
    // mypainter->front.setColor((QColor(255, 0, 0)));
    this->update();
}
*/
void MyGLWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    painter.begin(this);
    mypainter->draw(&painter, event);
    painter.end();
}

