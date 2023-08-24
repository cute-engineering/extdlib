#pragma once

#include <extdlib/base/any.h>
#include <extdlib/io/traits.h>

IoResult cli_fmt(IoWriter writer, Str format, AnyVa args);

#define cli_fmt$(WRITER, FMT, ...) \
    cli_fmt(io_writer$(WRITER), str$(FMT), any_va$(__VA_ARGS__))
