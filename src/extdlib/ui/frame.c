#include <extdlib/alloc/global.h>
#include <extdlib/ui/frame.h>

UiView *ui_frame_create(void)
{
    return ui_view_create$(UiFrame);
}
