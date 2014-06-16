#include "qhexspinbox.h"

QHexSpinBox::QHexSpinBox(QWidget *parent) :
    QSpinBox(parent)
{
    this->setWrapping(true);
    this->setRange(0x80000000,0x7fffffff);

}


QString QHexSpinBox::textFromValue(int value) const
{
    return "0x" + QString::number((uint)value,16).toUpper();
}


int QHexSpinBox::valueFromText(const QString &text) const
{
    bool ok;
    return text.toUInt( &ok, 16 );
}

void QHexSpinBox::show()
{
    QSpinBox::show();
}

