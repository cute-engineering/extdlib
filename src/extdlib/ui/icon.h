#pragma once

#include <extdlib/codec/ssfn2/ssfn2.h>
#include <extdlib/ui/view.h>

typedef struct
{
    UiView base;
} UiIcon;

#define ui_icon$(VIEW) ((UiIcon *)(VIEW))

UiView *ui_icon_create(void);
