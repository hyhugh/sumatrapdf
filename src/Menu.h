/* Copyright 2013 the SumatraPDF project authors (see AUTHORS file).
   License: GPLv3 */

#ifndef Menu_h
#define Menu_h

#include "resource.h"

#define SEP_ITEM "-----"

// those are defined here instead of resource.h to avoid
// having them overwritten by dialog editor
#define IDM_VIEW_LAYOUT_FIRST           IDM_VIEW_SINGLE_PAGE
#define IDM_VIEW_LAYOUT_LAST            IDM_VIEW_CONTINUOUS
#define IDM_ZOOM_FIRST                  IDM_ZOOM_FIT_PAGE
#define IDM_ZOOM_LAST                   IDM_ZOOM_CUSTOM
// note: IDM_VIEW_SINGLE_PAGE - IDM_VIEW_CONTINUOUS and also
//       IDM_ZOOM_FIT_PAGE - IDM_ZOOM_CUSTOM must be in a continuous range!
STATIC_ASSERT(IDM_VIEW_LAYOUT_LAST - IDM_VIEW_LAYOUT_FIRST == 3, view_layout_range);
STATIC_ASSERT(IDM_ZOOM_LAST - IDM_ZOOM_FIRST == 17, zoom_range);

struct MenuDef {
    const char *title;
    int         id;
    int         flags;
};

class WindowInfo;
class EbookWindow;

HMENU BuildMenuFromMenuDef(MenuDef menuDefs[], int menuLen, HMENU menu, int flagFilter=0);
HMENU BuildMenu(WindowInfo *win);
HMENU BuildMenu(EbookWindow *win);
void  OnContextMenu(WindowInfo* win, int x, int y);
void  OnAboutContextMenu(WindowInfo* win, int x, int y);
void  OnMenuZoom(WindowInfo* win, UINT menuId);
void  OnMenuCustomZoom(WindowInfo* win);
UINT  MenuIdFromVirtualZoom(float virtualZoom);
void  UpdateMenu(WindowInfo *win, HMENU m);
void  UpdateMenu(EbookWindow *win, HMENU m);

/* Define if you want to display an additional debug menu */
// TODO: temporarily show debug menus in pre-release builds to make it
// possible to crash to test changed crash handler
#if defined(DEBUG) || defined(SVN_PRE_RELEASE_VER)
#define SHOW_DEBUG_MENU_ITEMS
#endif

#endif
