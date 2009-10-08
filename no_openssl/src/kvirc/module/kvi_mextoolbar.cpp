//=============================================================================
//
//   File : kvi_mextoolbar.cpp
//   Creation date : Thu Sep 12 22:11:47 2002 GMT by Szymon Stefanek
//
//   This file is part of the KVirc irc client distribution
//   Copyright (C) 2002-2008 Szymon Stefanek (pragma at kvirc dot net)
//
//   This program is FREE software. You can redistribute it and/or
//   modify it under the terms of the GNU General Public License
//   as published by the Free Software Foundation; either version 2
//   of the License, or (at your opinion) any later version.
//
//   This program is distributed in the HOPE that it will be USEFUL,
//   but WITHOUT ANY WARRANTY; without even the implied warranty of
//   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
//   See the GNU General Public License for more details.
//
//   You should have received a copy of the GNU General Public License
//   along with this program. If not, write to the Free Software Foundation,
//   Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
//
//=============================================================================


#include "kvi_mextoolbar.h"
#include "kvi_frame.h"

KviMexToolBar::KviMexToolBar(KviModuleExtensionDescriptor * pDesc, const QString & szName)
: KviToolBar(szName,Qt::TopToolBarArea) , KviModuleExtension(pDesc)
{
	g_pFrame->registerModuleExtensionToolBar(this);
}

KviMexToolBar::~KviMexToolBar()
{
	g_pFrame->unregisterModuleExtensionToolBar(this);
}
