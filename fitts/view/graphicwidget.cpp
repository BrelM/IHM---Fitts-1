#include "graphicwidget.h"

GraphicWidget::GraphicWidget() {}

void GraphicWidget::mousePressEvent(QMouseEvent *event) {
    emit mouseClicked(event->position().x(), event->position().y());
}
