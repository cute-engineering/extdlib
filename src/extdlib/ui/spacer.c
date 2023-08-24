#include <extdlib/alloc/global.h>
#include <extdlib/ui/spacer.h>

UiView *ui_spacer_create(void)
{
    UiView *self = ui_view_create$(UiSpacer);
    ui_view_layout(self, "grow-1");

    return self;
}
