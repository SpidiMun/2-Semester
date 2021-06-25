#ifndef NODESHAPE_H
#define NODESHAPE_H

#include <QGraphicsItem>
#include <QPainter>
#include <QColor>

class NodeShape: public QGraphicsItem
{
public:
    NodeShape();
    ~NodeShape();
    QColor NodeBrushColor = Qt::cyan;
    QColor NodePenColor = Qt::black;
    void SetNodeCoords(double& x, double& y);
    void SetTextCoords(double& x, double& y);
    void SetNodeRadius(double& radius);

protected:
    double node_x, node_y;
    double text_x, text_y;
    double node_radius;
    virtual QRectF boundingRect() const; // Выделение области для рисования узла

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget); // Рисование узла

    // Обработчики события наведения мышки:

    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);      // Вхождение курсора в область прорисовки узла
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);      // Выход курсора из области прорисовки узла
};

#endif // NODESHAPE_H
