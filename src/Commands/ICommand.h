// This file is part of BowPad.
//
// Copyright (C) 2013 - Stefan Kueng
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// See <http://www.gnu.org/licenses/> for a copy of the full license text
//
#pragma once
#include "Scintilla.h"
#include "TabBar.h"
#include "Document.h"

#include <UIRibbon.h>
#include <UIRibbonPropertyHelpers.h>

class ICommand
{
public:
    ICommand(void * obj);
    virtual ~ICommand() {}

    /// Execute the command
    virtual bool        Execute() = 0;
    virtual UINT        GetCmdId() = 0;

    virtual void        ScintillaNotify(Scintilla::SCNotification * pScn);
    virtual void        TabNotify(TBHDR * ptbhdr);
    virtual HRESULT     IUICommandHandlerUpdateProperty(REFPROPERTYKEY key, const PROPVARIANT* ppropvarCurrentValue, PROPVARIANT* ppropvarNewValue);
    virtual HRESULT     IUICommandHandlerExecute(UI_EXECUTIONVERB verb, const PROPERTYKEY* key, const PROPVARIANT* ppropvarValue, IUISimplePropertySet* pCommandExecutionProperties);

protected:
    void                TabActivateAt(int index);
    int                 GetCurrentTabIndex();
    int                 GetTabCount();
    std::wstring        GetCurrentTitle();
    int                 GetSrcTab();
    int                 GetDstTab();

    int                 GetDocumentCount();
    CDocument           GetDocument(int index);
    void                SetDocument(int index, CDocument doc);

    sptr_t              ScintillaCall(unsigned int iMessage, uptr_t wParam = 0, sptr_t lParam = 0);
    LRESULT             SendMessageToMainWnd(UINT msg, WPARAM wParam, LPARAM lParam);
    void                UpdateStatusBar(bool bEverything);
    void                SetupLexerForLang(const std::wstring& lang);
    void                DocScrollClear(int type);
    void                DocScrollAddLineColor(int type, size_t line, COLORREF clr);
    void                Center(long startPos, long endPos);

    HWND                GetHwnd();
    bool                OpenFile(LPCWSTR file);
    bool                ReloadTab(int tab, int encoding);
    bool                SaveCurrentTab(bool bSaveAs = false);
    HRESULT             InvalidateUICommand(UI_INVALIDATIONS flags, const PROPERTYKEY *key);
    HRESULT             InvalidateUICommand(UINT32 cmdId, UI_INVALIDATIONS flags, const PROPERTYKEY *key);
    HRESULT             SetUICommandProperty(UINT32 commandId, REFPROPERTYKEY key, PROPVARIANT value);
    HRESULT             SetUICommandProperty(REFPROPERTYKEY key, PROPVARIANT value);

protected:
    void *              m_Obj;
};
