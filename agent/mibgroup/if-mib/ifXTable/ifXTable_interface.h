/*
 * Note: this file originally auto-generated by mib2c using
 *       version : 1.41 $ of : mfd-interface.m2c,v $
 *
 * $Id$
 */
/** @defgroup interface: Routines to interface to Net-SNMP
 *
 * \warning This code should not be modified, called directly,
 *          or used to interpret functionality. It is subject to
 *          change at any time.
 * 
 * @{
 */
/*
 * *********************************************************************
 * *********************************************************************
 * *********************************************************************
 * ***                                                               ***
 * ***  NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE  ***
 * ***                                                               ***
 * ***                                                               ***
 * ***       THIS FILE DOES NOT CONTAIN ANY USER EDITABLE CODE.      ***
 * ***                                                               ***
 * ***                                                               ***
 * ***       THE GENERATED CODE IS INTERNAL IMPLEMENTATION, AND      ***
 * ***                                                               ***
 * ***                                                               ***
 * ***    IS SUBJECT TO CHANGE WITHOUT WARNING IN FUTURE RELEASES.   ***
 * ***                                                               ***
 * ***                                                               ***
 * *********************************************************************
 * *********************************************************************
 * *********************************************************************
 */
#ifndef IFXTABLE_INTERFACE_H
#define IFXTABLE_INTERFACE_H

#ifdef __cplusplus
extern          "C" {
#endif


#include "ifXTable.h"

    /*
     ********************************************************************
     * Table declarations
     */

    /*
     * PUBLIC interface initialization routine 
     */
    void           
        _ifXTable_initialize_interface(ifXTable_registration_ptr user_ctx,
                                       u_long flags);

    ifXTable_rowreq_ctx *ifXTable_allocate_rowreq_ctx(void *);
    void            ifXTable_release_rowreq_ctx(ifXTable_rowreq_ctx *
                                                rowreq_ctx);

    int             ifXTable_index_to_oid(netsnmp_index * oid_idx,
                                          ifXTable_mib_index * mib_idx);
    int             ifXTable_index_from_oid(netsnmp_index * oid_idx,
                                            ifXTable_mib_index * mib_idx);

    /*
     * access to certain internals. use with caution!
     */
    void            ifXTable_valid_columns_set(netsnmp_column_info *vc);


#ifdef __cplusplus
}
#endif
#endif                          /* IFXTABLE_INTERFACE_H */
