#include <extdlib/time/convert.h>
#include <extdlib/time/query.h>
#include <embed/clock.h>

Tick tick_now(void)
{
    return embed_time_current_tick();
}

TimeStamp timestamp_now(void)
{
    return embed_time_current_timestamp();
}

Date date_now(void)
{
    return datetime_now().date;
}

Time time_now(void)
{
    return datetime_now().time;
}

DateTime datetime_now(void)
{
    return timestamp_to_datetime(timestamp_now());
}

NanoSeconds time_ns_now(void)
{
    return embed_time_current_nsec();
}
