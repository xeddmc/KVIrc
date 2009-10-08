#ifndef _KVI_CUSTOMTOOLBARDESCRIPTOR_H_
#define _KVI_CUSTOMTOOLBARDESCRIPTOR_H_
//=============================================================================
//
//   File : kvi_customtoolbardescriptor.h
//   Creation date : Sun 05 Dec 2004 18:20:58 by Szymon Stefanek
//
//   This file is part of the KVIrc IRC client distribution
//   Copyright (C) 2004-2008 Szymon Stefanek <pragma at kvirc dot net>
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

#include "kvi_settings.h"
#include "kvi_qstring.h"
#include "kvi_pointerlist.h"

class KviCustomToolBar;
class KviConfig;
class KviKvsScript;


class KVIRC_API KviCustomToolBarDescriptor
{
	friend class KviCustomToolBar;
	friend class KviCustomToolBarManager;
protected:
	KviCustomToolBarDescriptor(const QString & szId, const QString & szLabelCode);
public:
	~KviCustomToolBarDescriptor();
protected:
	QString               m_szId;
	QString               m_szIconId;
	QString               m_szParsedLabel;
	KviPointerList<QString> * m_pActions;
	KviCustomToolBar    * m_pToolBar;
	int                   m_iInternalId;
	bool                  m_bVisibleAtStartup;
	KviKvsScript        * m_pLabelScript;
public:
	const QString & iconId(){ return m_szIconId; };
	const QString & label();
	const QString & labelCode();
	const QString & id(){ return m_szId; };
	int internalId(){ return m_iInternalId; }; // useful only for KviFrame
	KviCustomToolBar * toolBar(){ return m_pToolBar; };
	KviCustomToolBar * createToolBar();
	void setIconId(const QString &szIconId){ m_szIconId = szIconId; };
	bool addAction(const QString &szAction);
	bool removeAction(const QString &szAction);
	bool removeAction(unsigned int iAction);
	void clear();
	void rename(const QString &szNewName);
	KviPointerList<QString> * actions(){ return m_pActions; };
	void updateToolBar();
protected:
	void createLabelScript(const QString &szNewLabelCode);
	void fillToolBar();
	bool load(KviConfig * cfg);
	void save(KviConfig * cfg);
	void registerToolBar(KviCustomToolBar * t);
	void unregisterToolBar(KviCustomToolBar * t);
};

#endif //_KVI_CUSTOMTOOLBARDESCRIPTOR_H_
