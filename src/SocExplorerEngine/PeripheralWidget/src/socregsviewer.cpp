/*------------------------------------------------------------------------------
--  This file is a part of the SocExplorer Software
--  Copyright (C) 2014, Plasma Physics Laboratory - CNRS
--
--  This program is free software; you can redistribute it and/or modify
--  it under the terms of the GNU General Public License as published by
--  the Free Software Foundation; either version 3 of the License, or
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
/*--                  Author : Alexis Jeandet
--                     Mail : alexis.jeandet@member.fsf.org
----------------------------------------------------------------------------*/
#include "socregsviewer.h"

socRegsViewer::socRegsViewer(const QString &name, QWidget *parent) :
    QScrollArea(parent)
{
    p_name = name;
    p_scrollAreaWdgt = new QWidget(this);
    p_scrollAreaWdgtLayout = new QGridLayout(p_scrollAreaWdgt);
    //p_layout = new QGridLayout(this);
    p_nameLabel = new QLabel(name);
    setWidget(p_scrollAreaWdgt);
    setWidgetResizable(true);
    p_scrollAreaWdgt->setLayout(p_scrollAreaWdgtLayout);
    p_scrollAreaWdgtLayout->addWidget(p_nameLabel,0,0,1,1);
}

peripheralWidget *socRegsViewer::peripheral(int index)
{
    if(index>=0 && index<p_peripherals.count())
    {
        return p_peripherals.at(index);
    }
    return NULL;
}

void socRegsViewer::addPeripheral(peripheralWidget *peripheral)
{
    if(peripheral!=NULL)
    {
        p_peripherals.append(peripheral);
        p_scrollAreaWdgtLayout->addWidget(peripheral,p_peripherals.count(),0,1,-1);
        connect(peripheral,SIGNAL(clicked(peripheralWidget*)),this,SLOT(periphClicked(peripheralWidget*)));
        connect(peripheral,SIGNAL(upSig(peripheralWidget*,int)),this,SLOT(periphUp(peripheralWidget*,int)));
        connect(peripheral,SIGNAL(downSig(peripheralWidget*,int)),this,SLOT(periphDown(peripheralWidget*,int)));
    }
}

void socRegsViewer::periphClicked(peripheralWidget *sender)
{
    peripheralWidget * item;
    if(sender!=NULL)
    {
        for(int i=0;i<p_peripherals.count();i++)
        {
            item = p_peripherals.at(i);
            if(item!=sender)
            {
                item->leave();
            }
        }
    }
}

void socRegsViewer::periphUp(peripheralWidget *sender, int cursorIndex)
{
    int index,senderIndex;
    if(sender!=NULL)
    {
        index =senderIndex= p_peripherals.indexOf(sender);
        while(index!=-1 && index!=0)
        {
            if(p_peripherals.at(index-1)->count()>0)
            {
                p_peripherals.at(senderIndex)->leave();
                p_peripherals.at(index-1)->enter(cursorIndex,false);
                ensureWidgetVisible(p_peripherals.at(index-1));
                break;
            }
            index--;
        }
    }
}

void socRegsViewer::periphDown(peripheralWidget *sender, int cursorIndex)
{
    int index,senderIndex;
    if(sender!=NULL)
    {
        index=senderIndex= p_peripherals.indexOf(sender);
        while((index!=-1) && (index<(p_peripherals.count()-1)))
        {
            if(p_peripherals.at(index+1)->count()>0)
            {
                p_peripherals.at(senderIndex)->leave();
                p_peripherals.at(index+1)->enter(cursorIndex);
                ensureWidgetVisible(p_peripherals.at(index+1));
                break;
            }
            index++;
        }
    }
}
