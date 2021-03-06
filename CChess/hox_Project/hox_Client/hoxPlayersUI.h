/***************************************************************************
 *  Copyright 2007-2009 Huy Phan  <huyphan@playxiangqi.com>                *
 *                      Bharatendra Boddu (bharathendra at yahoo dot com)  *
 *                                                                         * 
 *  This file is part of HOXChess.                                         *
 *                                                                         *
 *  HOXChess is free software: you can redistribute it and/or modify       *
 *  it under the terms of the GNU General Public License as published by   *
 *  the Free Software Foundation, either version 3 of the License, or      *
 *  (at your option) any later version.                                    *
 *                                                                         *
 *  HOXChess is distributed in the hope that it will be useful,            *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of         *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the          *
 *  GNU General Public License for more details.                           *
 *                                                                         *
 *  You should have received a copy of the GNU General Public License      *
 *  along with HOXChess.  If not, see <http://www.gnu.org/licenses/>.      *
 ***************************************************************************/

/////////////////////////////////////////////////////////////////////////////
// Name:            hoxPlayersUI.h
// Created:         04/20/2008
//
// Description:     The UI containing a list of Players.
/////////////////////////////////////////////////////////////////////////////

#ifndef __INCLUDED_HOX_PLAYERS_UI_H__
#define __INCLUDED_HOX_PLAYERS_UI_H__

#include <wx/listctrl.h>
#include <wx/imaglist.h>
#include "hoxTypes.h"

// ---------------------------------------------------------------------------
// hoxPlayersUI class
// ---------------------------------------------------------------------------

class hoxPlayersUI : public wxListCtrl
{
public:
    /**
     * Type of Players-UI.
     */
    enum UIType
    {
        UI_TYPE_SITE,   /* This list belongs to a Site. */
        UI_TYPE_TABLE   /* This list belongs to a Table. */
    };

    /**
     * Sorting order for players in the list.
     */
    enum SortOrder
    {
        PLAYERS_SORT_NONE,
        PLAYERS_SORT_ASCENDING,
        PLAYERS_SORT_DESCENDING
    };

    /**
     * Request types to communicate with the Owner.
     */
    enum EventType
    {
        EVENT_TYPE_INFO,
        EVENT_TYPE_INVITE,
        EVENT_TYPE_MSG
    };

    /**
     * The UI's Owner. 
     */
    class UIOwner
    {
    public:
        virtual void OnPlayersUIEvent( EventType       eventType,
                                       const wxString& sPlayerId ) = 0;
    };

public:
    hoxPlayersUI( wxWindow* parent,
                  UIType    uiType );
    virtual ~hoxPlayersUI();

    void SetOwner( UIOwner* owner ) { m_owner = owner; }

    bool AddPlayer( const wxString&       sPlayerId,
                    const int             nPlayerScore,
                    const hoxPlayerStatus playerStatus = hoxPLAYER_STATUS_UNKNOWN );

    bool RemovePlayer( const wxString& sPlayerId );

    bool UpdateScore( const wxString& sPlayerId,
                      const int       nPlayerScore );

    bool UpdateStatus( const wxString&       sPlayerId,
                       const hoxPlayerStatus playerStatus );

    bool HasPlayer( const wxString& sPlayerId ) const;

    /**
     * Get the score of given Player.
     * @return hoxSCORE_UNKNOWN - if the Player is not found.
     */
    int GetPlayerScore( const wxString& sPlayerId ) const;

    void RemoveAllPlayers();

    wxString GetSelectedPlayer() const;

    void OnLMouseDClick( wxMouseEvent& event );
    void OnContextMenu( wxContextMenuEvent& event );
    void OnPlayerInfo( wxCommandEvent& event );
    void OnPlayerInvite( wxCommandEvent& event );
    void OnPlayerMsg( wxCommandEvent& event );
    void OnColumnClick( wxListEvent& event );

private:
    long _FindPlayerIndex( const wxString& sPlayerId ) const;

    wxString _GetCellContent( const long row_number,
                              const int  column ) const;

    void _InitializeImageList();
    int  _StatusToImageIndex( const hoxPlayerStatus playerStatus ) const;

	void _GetDefaultLayout( int& wId,
                            int& wRating ) const;
    void _SaveDefaultLayout( const int wId,
                             const int wRating );

private:
    const UIType      m_uiType;
    UIOwner*          m_owner;   // This UI's owner.

    SortOrder         m_sortOrderByRating;
            /* NOTE: Only support sorting by Rating for now */

    wxImageList*      m_imageList;

    DECLARE_EVENT_TABLE()

}; // END of hoxPlayersUI

#endif /* __INCLUDED_HOX_PLAYERS_UI_H__ */
