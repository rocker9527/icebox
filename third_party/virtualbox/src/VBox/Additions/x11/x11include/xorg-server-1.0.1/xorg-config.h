/* include/xorg-config.h.  Generated by configure.  */
/* xorg-config.h.in: not at all generated.                      -*- c -*-
 *
 * This file differs from xorg-server.h.in in that -server is installed
 * with the rest of the SDK for external drivers/modules to use, whereas
 * -config is for internal use only (i.e. building the DDX).
 *
 */

#ifndef _XORG_CONFIG_H_
#define _XORG_CONFIG_H_

#include <dix-config.h>
#include <xkb-config.h>

/* Building Xorg server. */
#define XORGSERVER 1

/* Current X.Org version. */
#define XORG_VERSION_CURRENT (((7) * 10000000) + ((0) * 100000) + ((0) * 1000) + 0)

/* Need XFree86 libc-replacement typedefs. */
#define NEED_XF86_TYPES 1

/* Need XFree86 libc-replacement functions. */
#define NEED_XF86_PROTOTYPES 1

/* Name of X server. */
#define __XSERVERNAME__ "Xorg"

/* URL to go to for support. */
#define __VENDORDWEBSUPPORT__ "http://wiki.x.org"

/* Prefer dlloader modules to elfloader */
#define DLOPEN_HACK 1

/* Use libdl-based loader. */
#define DLOPEN_SUPPORT 1

/* Built-in output drivers. */
#define DRIVERS {}

/* Built-in input drivers. */
#define IDRIVERS {}

/* Path to configuration file. */
#define XF86CONFIGFILE "xorg.conf"

/* Path to configuration file. */
#define __XCONFIGFILE__ "xorg.conf"

/* Path to loadable modules. */
#define DEFAULT_MODULE_PATH "/opt/debrix/lib/xorg/modules"

/* Path to server log file. */
#define DEFAULT_LOGPREFIX "/opt/debrix/var/log/Xorg."

/* Building DRI-capable DDX. */
#define XF86DRI 1

/* Solaris 8 or later? */
/* #undef __SOL8__ */

/* Whether to use pixmap privates */
#define PIXPRIV 1

/* Define to 1 if you have the `walkcontext' function (used on Solaris for
   xorg_backtrace in hw/xfree86/common/xf86Events.c */
/* #undef HAVE_WALKCONTEXT */

/* Define to 1 if unsigned long is 64 bits. */
#define _XSERVER64 1

/* Building vgahw module */
#define WITH_VGAHW 1

/* Define to 1 if NetBSD built-in MTRR support is available */
/* #undef HAS_MTRR_BUILTIN */

/* Define to 1 if BSD MTRR support is available */
/* #undef HAS_MTRR_SUPPORT */

/* NetBSD PIO alpha IO */
/* #undef USE_ALPHA_PIO */

/* BSD AMD64 iopl */
/* #undef USE_AMD64_IOPL */

/* BSD /dev/io */
/* #undef USE_DEV_IO */

/* BSD i386 iopl */
/* #undef USE_I386_IOPL */

/* System is BSD-like */
/* #undef CSRG_BASED */

/* System has PC console */
/* #undef PCCONS_SUPPORT */

/* System has PCVT console */
/* #undef PCVT_SUPPORT */

/* System has syscons console */
/* #undef SYSCONS_SUPPORT */

/* System has wscons console */
/* #undef WSCONS_SUPPORT */

#endif /* _XORG_CONFIG_H_ */
