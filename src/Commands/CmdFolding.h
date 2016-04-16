// This file is part of BowPad.
//
// Copyright (C) 2015-2016 - Stefan Kueng
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
#include "ICommand.h"
#include "BowPadUI.h"

class CCmdFoldAll : public ICommand
{
public:

    CCmdFoldAll(void * obj);

    ~CCmdFoldAll();

    bool Execute() override;

    UINT GetCmdId() override { return cmdFoldAll; }

};

class CCmdFoldLevel : public ICommand
{
public:
    CCmdFoldLevel(UINT customId, void * obj);
    ~CCmdFoldLevel(void) {}

    bool Execute() override;
    UINT GetCmdId() override { return m_customCmdId; }

private:
    UINT            m_customId;
    UINT            m_customCmdId;
};

class CCmdInitFoldingMargin : public ICommand
{
public:
    CCmdInitFoldingMargin(void* obj);
    ~CCmdInitFoldingMargin() = default;

    bool Execute() override;
    UINT GetCmdId() override { return cmdInitFoldingMargin; }
    void TabNotify(TBHDR* ptbhdr) override;

private:
};

class CCmdFoldingOn : public ICommand
{
public:
    CCmdFoldingOn(void* obj);
    ~CCmdFoldingOn() = default;

    bool Execute() override;
    UINT GetCmdId() override { return cmdFoldingOn; }

private:
};

class CCmdFoldingOff : public ICommand
{
public:
    CCmdFoldingOff(void * obj);
    ~CCmdFoldingOff() = default;

    bool Execute() override;
    UINT GetCmdId() override { return cmdFoldingOff; }

private:
};
