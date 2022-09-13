// Copyright 2012-2022 David Robillard <d@drobilla.net>
// SPDX-License-Identifier: ISC

#ifndef PUGL_SRC_X11_H
#define PUGL_SRC_X11_H

#include "attributes.h"
#include "types.h"

#include "pugl/pugl.h"

#include <X11/X.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
  Atom CLIPBOARD;
  Atom UTF8_STRING;
  Atom WM_PROTOCOLS;
  Atom WM_DELETE_WINDOW;
  Atom PUGL_CLIENT_MSG;
  Atom NET_WM_NAME;
  Atom NET_WM_STATE;
  Atom NET_WM_STATE_DEMANDS_ATTENTION;
  Atom NET_WM_STATE_HIDDEN;
  Atom NET_WM_WINDOW_TYPE;
  Atom NET_WM_WINDOW_TYPE_DESKTOP;
  Atom NET_WM_WINDOW_TYPE_DOCK;
  Atom NET_WM_WINDOW_TYPE_TOOLBAR;
  Atom NET_WM_WINDOW_TYPE_MENU;
  Atom NET_WM_WINDOW_TYPE_UTILITY;
  Atom NET_WM_WINDOW_TYPE_SPLASH;
  Atom NET_WM_WINDOW_TYPE_DIALOG;
  Atom NET_WM_WINDOW_TYPE_DROPDOWN_MENU;
  Atom NET_WM_WINDOW_TYPE_POPUP_MENU;
  Atom NET_WM_WINDOW_TYPE_TOOLTIP;
  Atom NET_WM_WINDOW_TYPE_NOTIFICATION;
  Atom NET_WM_WINDOW_TYPE_COMBO;
  Atom NET_WM_WINDOW_TYPE_DND;
  Atom NET_WM_WINDOW_TYPE_NORMAL;
  Atom TARGETS;
  Atom text_uri_list;
} PuglX11Atoms;

typedef struct {
  XID       alarm;
  PuglView* view;
  uintptr_t id;
} PuglTimer;

typedef struct {
  Atom          selection;
  Atom          property;
  Window        source;
  Atom*         formats;
  char**        formatStrings;
  unsigned long numFormats;
  uint32_t      acceptedFormatIndex;
  Atom          acceptedFormat;
  PuglBlob      data;
} PuglX11Clipboard;

struct PuglWorldInternalsImpl {
  Display*     display;
  PuglX11Atoms atoms;
  XIM          xim;
  double       scaleFactor;
  PuglTimer*   timers;
  size_t       numTimers;
  XID          serverTimeCounter;
  int          syncEventBase;
  bool         syncSupported;
  bool         dispatchingEvents;
};

struct PuglInternalsImpl {
  XVisualInfo*     vi;
  Window           win;
  XIC              xic;
  PuglSurface*     surface;
  PuglEvent        pendingConfigure;
  PuglEvent        pendingExpose;
  PuglX11Clipboard clipboard;
  int              screen;
  const char*      cursorName;
};

PUGL_WARN_UNUSED_RESULT
PUGL_API
PuglStatus
puglX11Configure(PuglView* view);

#endif // PUGL_SRC_X11_H
