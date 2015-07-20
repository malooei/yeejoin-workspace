/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "mount.h"
/* This file is copied from RFC1813
 * Copyright 1995 Sun Micrososystems (I assume)
 */

bool_t
xdr_fhandle3(register XDR *xdrs, fhandle3 *objp)
{

#if defined(_LP64) || defined(_KERNEL)
	register int *buf;
#else
	register long *buf;
#endif

	if (!xdr_bytes(xdrs, (char **)&objp->fhandle3_val, (u_int *) &objp->fhandle3_len, FHSIZE3))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_dirpath(register XDR *xdrs, dirpath *objp)
{

#if defined(_LP64) || defined(_KERNEL)
	register int *buf;
#else
	register long *buf;
#endif

	if (!xdr_string(xdrs, objp, MNTPATHLEN))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_name(register XDR *xdrs, name *objp)
{

#if defined(_LP64) || defined(_KERNEL)
	register int *buf;
#else
	register long *buf;
#endif

	if (!xdr_string(xdrs, objp, MNTNAMLEN))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_exports(register XDR *xdrs, exports *objp)
{

#if defined(_LP64) || defined(_KERNEL)
	register int *buf;
#else
	register long *buf;
#endif

	if (!xdr_pointer(xdrs, (char **)objp, sizeof (struct exportnode), (xdrproc_t) xdr_exportnode))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_groups(register XDR *xdrs, groups *objp)
{

#if defined(_LP64) || defined(_KERNEL)
	register int *buf;
#else
	register long *buf;
#endif

	if (!xdr_pointer(xdrs, (char **)objp, sizeof (struct groupnode), (xdrproc_t) xdr_groupnode))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_mountlist(register XDR *xdrs, mountlist *objp)
{

#if defined(_LP64) || defined(_KERNEL)
	register int *buf;
#else
	register long *buf;
#endif

	if (!xdr_pointer(xdrs, (char **)objp, sizeof (struct mountbody), (xdrproc_t) xdr_mountbody))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_mountstat3(register XDR *xdrs, mountstat3 *objp)
{
	int enum_objp;

#if defined(_LP64) || defined(_KERNEL)
	register int *buf;
#else
	register long *buf;
#endif

	enum_objp = *objp;

	if (!xdr_enum(xdrs, (enum_t *)&enum_objp))
	{
		*objp = enum_objp;
		return (FALSE);
	}

	return (TRUE);
}

bool_t
xdr_mountres3_ok(register XDR *xdrs, mountres3_ok *objp)
{

#if defined(_LP64) || defined(_KERNEL)
	register int *buf;
#else
	register long *buf;
#endif

	if (!xdr_fhandle3(xdrs, &objp->fhandle))
		return (FALSE);
	if (!xdr_array(xdrs, (char **)&objp->auth_flavors.auth_flavors_val, (u_int *) &objp->auth_flavors.auth_flavors_len, ~0,
		sizeof (int), (xdrproc_t) xdr_int))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_mountres3(register XDR *xdrs, mountres3 *objp)
{

#if defined(_LP64) || defined(_KERNEL)
	register int *buf;
#else
	register long *buf;
#endif

	if (!xdr_mountstat3(xdrs, &objp->fhs_status))
		return (FALSE);
	switch (objp->fhs_status) {
	case MNT3_OK:
		if (!xdr_mountres3_ok(xdrs, &objp->mountres3_u.mountinfo))
			return (FALSE);
		break;
	}
	return (TRUE);
}

bool_t
xdr_mountbody(register XDR *xdrs, mountbody *objp)
{

#if defined(_LP64) || defined(_KERNEL)
	register int *buf;
#else
	register long *buf;
#endif

	if (!xdr_name(xdrs, &objp->ml_hostname))
		return (FALSE);
	if (!xdr_dirpath(xdrs, &objp->ml_directory))
		return (FALSE);
	if (!xdr_mountlist(xdrs, &objp->ml_next))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_groupnode(register XDR *xdrs, groupnode *objp)
{

#if defined(_LP64) || defined(_KERNEL)
	register int *buf;
#else
	register long *buf;
#endif

	if (!xdr_name(xdrs, &objp->gr_name))
		return (FALSE);
	if (!xdr_groups(xdrs, &objp->gr_next))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_exportnode(register XDR *xdrs, exportnode *objp)
{

#if defined(_LP64) || defined(_KERNEL)
	register int *buf;
#else
	register long *buf;
#endif

	if (!xdr_dirpath(xdrs, &objp->ex_dir))
		return (FALSE);
	if (!xdr_groups(xdrs, &objp->ex_groups))
		return (FALSE);
	if (!xdr_exports(xdrs, &objp->ex_next))
		return (FALSE);
	return (TRUE);
}
