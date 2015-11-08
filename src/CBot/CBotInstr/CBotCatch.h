/*
 * This file is part of the Colobot: Gold Edition source code
 * Copyright (C) 2001-2015, Daniel Roux, EPSITEC SA & TerranovaTeam
 * http://epsitec.ch; http://colobot.info; http://github.com/colobot
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see http://gnu.org/licenses
 */

#pragma once

// Modules inlcude
#include "CBot.h"

// Local include

// Global include

/*!
 * \brief The CBotCatch class. Compiles instruction "catch".
 */
class CBotCatch : public CBotInstr
{
public:

    /*!
     * \brief CBotCatch
     */
    CBotCatch();

    /*!
     * \brief CBotCatch
     */
    ~CBotCatch();

    /*!
     * \brief Compile
     * \param p
     * \param pStack
     * \return
     */
    static CBotCatch* Compile(CBotToken* &p, CBotCStack* pStack);

    /*!
     * \brief TestCatch Routine to see if the catch is to do or not.
     * \param pj
     * \param val
     * \return
     */
    bool TestCatch(CBotStack* &pj, int val);

    /*!
     * \brief Execute Execution of "catch".
     * \param pj
     * \return
     */
    bool Execute(CBotStack* &pj) override;

    /*!
     * \brief RestoreState
     * \param pj
     * \param bMain
     */
    void RestoreState(CBotStack* &pj, bool bMain) override;

    /*!
     * \brief RestoreCondState
     * \param pj
     * \param bMain
     */
    void RestoreCondState(CBotStack* &pj, bool bMain);


private:
    //! Instructions
    CBotInstr* m_Block;
    //! Condition
    CBotInstr* m_Cond;
    //! Following catch
    CBotCatch* m_next;

    friend class CBotTry;
};
