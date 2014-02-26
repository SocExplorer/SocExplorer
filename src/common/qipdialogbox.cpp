/*------------------------------------------------------------------------------
--  This file is a part of the SocExplorer Software
--  Copyright (C) 2014, Laboratory of Plasmas Physic - CNRS
--
--  This program is free software; you can redistribute it and/or modify
--  it under the terms of the GNU General Public License as published by
--  the Free Software Foundation; either version 2 of the License, or
--  (at your option) any later version.
--
--  This program is distributed in the hope that it will be useful,
--  but WITHOUT ANY WARRANTY; without even the implied warranty of
--  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
--  GNU General Public License for more details.
--
--  You should have received a copy of the GNU General Public License
--  along with this program; if not, write to the Free Software
--  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
-------------------------------------------------------------------------------*/
/*--                  Author : Paul Leroy
--                     Mail : paul.leroy@lpp.polytechnique.fr
----------------------------------------------------------------------------*/
#include "qipdialogbox.h"
#include <QSpinBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QString>
#include <QLocale>

QIPDialogBox::QIPDialogBox(QWidget *parent) :
    QWidget(parent)
{
    QHBoxLayout *addressLayout = new QHBoxLayout;
    QVBoxLayout *mainLayout = new QVBoxLayout;
    addressPart1 = new QSpinBox;
    addressPart2 = new QSpinBox;
    addressPart3 = new QSpinBox;
    addressPart4 = new QSpinBox;

    addressPart1->setRange(0, 255);
    addressPart1->setValue(129);
    addressPart1->setButtonSymbols(QAbstractSpinBox::NoButtons);

    addressPart2->setRange(0, 255);
    addressPart2->setValue(104);
    addressPart2->setButtonSymbols(QAbstractSpinBox::NoButtons);

    addressPart3->setRange(0, 255);
    addressPart3->setValue(27);
    addressPart3->setButtonSymbols(QAbstractSpinBox::NoButtons);

    addressPart4->setRange(0, 255);
    addressPart4->setValue(113);
    addressPart4->setButtonSymbols(QAbstractSpinBox::NoButtons);

    valueChanged();

    connect(addressPart1, SIGNAL(valueChanged(int)), this, SLOT(valueChanged()));
    connect(addressPart2, SIGNAL(valueChanged(int)), this, SLOT(valueChanged()));
    connect(addressPart3, SIGNAL(valueChanged(int)), this, SLOT(valueChanged()));
    connect(addressPart4, SIGNAL(valueChanged(int)), this, SLOT(valueChanged()));

    addressLayout->addWidget(addressPart1);
    addressLayout->addWidget(addressPart2);
    addressLayout->addWidget(addressPart3);
    addressLayout->addWidget(addressPart4);
    mainLayout->addLayout(addressLayout);
    //mainLayout->addWidget(labelGRESBIP);

    setLayout(mainLayout);
}

void QIPDialogBox::valueChanged() // SLOT
{
    gresbIP = addressPart1->cleanText();
    gresbIP.append(".");
    gresbIP.append(addressPart2->cleanText());
    gresbIP.append(".");
    gresbIP.append(addressPart3->cleanText());
    gresbIP.append(".");
    gresbIP.append(addressPart4->cleanText());
}

QString QIPDialogBox::getIP()
{
    return(gresbIP);
}

void QIPDialogBox::setIP(unsigned char address1, unsigned char address2, unsigned char address3, unsigned char address4)
{
    addressPart1->setValue(address1);
    addressPart2->setValue(address2);
    addressPart3->setValue(address3);
    addressPart4->setValue(address4);
    addressPart1->repaint();
    addressPart2->repaint();
    addressPart3->repaint();
    addressPart4->repaint();
}

unsigned char QIPDialogBox::get_addressPart1()
{
    return (unsigned char) addressPart1->value();
}

unsigned char QIPDialogBox::get_addressPart2()
{
    return (unsigned char) addressPart2->value();
}

unsigned char QIPDialogBox::get_addressPart3()
{
    return (unsigned char) addressPart3->value();
}

unsigned char QIPDialogBox::get_addressPart4()
{
    return (unsigned char) addressPart4->value();
}
