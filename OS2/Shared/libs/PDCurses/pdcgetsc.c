/************************************************************************ 
 * This file is part of PDCurses. PDCurses is public domain software;	*
 * you may use it for any purpose. This software is provided AS IS with	*
 * NO WARRANTY whatsoever.						*
 *									*
 * If you use PDCurses in an application, an acknowledgement would be	*
 * appreciated, but is not mandatory. If you make corrections or	*
 * enhancements to PDCurses, please forward them to the current		*
 * maintainer for the benefit of other users.				*
 *									*
 * See the file maintain.er for details of the current maintainer.	*
 ************************************************************************/

#include "pdcos2.h"

RCSID("$Id: pdcgetsc.c,v 1.37 2007/06/14 13:50:26 wmcbrine Exp $")

/* return width of screen/viewport */

int PDC_get_columns(void)
{
#ifdef EMXVIDEO
	int rows = 0;
#else
	VIOMODEINFO modeInfo = {0};
#endif
	int cols = 0;
	const char *env_cols;

	PDC_LOG(("PDC_get_columns() - called\n"));

#ifdef EMXVIDEO
	v_dimen(&cols, &rows);
#else
	modeInfo.cb = sizeof(modeInfo);
	VioGetMode(&modeInfo, 0);
	cols = modeInfo.col;
#endif
	env_cols = getenv("COLS");

	if (env_cols)
		cols = min(atoi(env_cols), cols);

	PDC_LOG(("PDC_get_columns() - returned: cols %d\n", cols));

	return cols;
}

/* get the cursor size/shape */

int PDC_get_cursor_mode(void)
{
#ifdef EMXVIDEO
	int curstart = 0, curend = 0;
#else
	VIOCURSORINFO cursorInfo;
#endif
	PDC_LOG(("PDC_get_cursor_mode() - called\n"));

#ifdef EMXVIDEO
	v_getctype(&curstart, &curend);
	return (curstart << 8) | curend;
#else
	VioGetCurType (&cursorInfo, 0);

	return (cursorInfo.yStart << 8) | cursorInfo.cEnd;
#endif
}

/* return number of screen rows */

int PDC_get_rows(void)
{
#ifdef EMXVIDEO
	int cols = 0;
#else
	VIOMODEINFO modeInfo = {0};
#endif
	int rows = 0;
	const char *env_rows;

	PDC_LOG(("PDC_get_rows() - called\n"));

 /* use the value from LINES environment variable, if set. MH 10-Jun-92 */
 /* and use the minimum of LINES and *ROWS.                MH 18-Jun-92 */

#ifdef EMXVIDEO
	v_dimen(&cols, &rows);
#else
	modeInfo.cb = sizeof(modeInfo);
	VioGetMode(&modeInfo, 0);
	rows = modeInfo.row;
#endif
	env_rows = getenv("LINES");

	if (env_rows)
		rows = min(atoi(env_rows), rows);

	PDC_LOG(("PDC_get_rows() - returned: rows %d\n", rows));

	return rows;
}
