/*
 *  Copyright (C) 2014  Efstathios Chatzikyriakidis (stathis.chatzikyriakidis@gmail.com).
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdarg.h>
#include <syslog.h>

#include "logging-utility.h"

/*
 * functions.
 */

void
open_logging_for_daemon (const string_t const identity)
{
  openlog (identity, LOG_PID, LOG_DAEMON);
}

void
close_logging (void)
{
  closelog ();
}

void
log_error (const string_t const format, ...)
{
  va_list args;

  va_start (args, format);

  vsyslog (LOG_ERR, format, args);

  va_end (args);
}

void
log_warning (const string_t const format, ...)
{
  va_list args;

  va_start (args, format);

  vsyslog (LOG_WARNING, format, args);

  va_end (args);
}

void
log_info (const string_t const format, ...)
{
  va_list args;

  va_start (args, format);

  vsyslog (LOG_INFO, format, args);

  va_end (args);
}
