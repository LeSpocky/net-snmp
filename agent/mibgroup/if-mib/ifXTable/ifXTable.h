/*
 * Note: this file originally auto-generated by mib2c using
 *       version : 1.32 $ of : mfd-top.m2c,v $
 *
 * $Id$
 */
#ifndef IFXTABLE_H
#define IFXTABLE_H

#ifdef __cplusplus
extern          "C" {
#endif


/** @defgroup misc misc: Miscelaneous routines
 *
 * @{
 */
#include <net-snmp/library/asn1.h>
#include <net-snmp/data_access/interface.h>

#include "if-mib/ifTable/ifTable.h"

    /*
     * OID, column number and enum definions for  
     */
#include "ifXTable_constants.h"

    /*
     *********************************************************************
     * function declarations
     */
    void            init_ifXTable(void);

    /*
     *********************************************************************
     * Table declarations
     */
/**********************************************************************
 **********************************************************************
 ***
 *** Table ifXTable
 ***
 **********************************************************************
 **********************************************************************/
    /*
     * ifXTable is subid 1 of ifMIBObjects.
     * Its status is Current.
     * OID: .1.3.6.1.2.1.31.1.1, length: 9
     *
     * we share data structures (data too, in fact) with ifTable
         */
#include "if-mib/ifTable/ifTable.h"

    typedef ifTable_registration_ptr ifXTable_registration_ptr;
    typedef ifTable_data             ifXTable_data;
    typedef ifTable_undo_data        ifXTable_undo_data;
    typedef ifTable_mib_index        ifXTable_mib_index;
    typedef ifTable_rowreq_ctx       ifXTable_rowreq_ctx;
    typedef ifTable_ref_rowreq_ctx   ifXTable_ref_rowreq_ctx;

#define ifXTable_data_list           ifTable_data_list
#define ifXTable_reg                 ifTable_reg

    /*
     *********************************************************************
     * function prototypes
     */
    int             ifXTable_pre_request(ifXTable_registration_ptr
                                         user_context);
    int             ifXTable_post_request(ifXTable_registration_ptr
                                          user_context);

    int             ifXTable_init_rowreq_ctx(ifXTable_rowreq_ctx *
                                             rowreq_ctx);
    void            ifXTable_cleanup_rowreq_ctx(ifXTable_rowreq_ctx *
                                                rowreq_ctx);

    int             ifXTable_check_dependencies(ifXTable_rowreq_ctx *
                                                rowreq_ctx);
    int             ifXTable_commit(ifXTable_rowreq_ctx * rowreq_ctx);

    extern oid      ifXTable_oid[];
    extern int      ifXTable_oid_size;


#include "ifXTable_interface.h"
#include "ifXTable_data_access.h"
    /*
     *********************************************************************
     * GET function declarations
     */

    /*
     *********************************************************************
     * GET Table declarations
     */
/**********************************************************************
 **********************************************************************
 ***
 *** Table ifXTable
 ***
 **********************************************************************
 **********************************************************************/
    /*
     * ifXTable is subid 1 of ifMIBObjects.
     * Its status is Current.
     * OID: .1.3.6.1.2.1.31.1.1, length: 9
     */
    /*
     * indexes
     */

    int             ifName_get(ifXTable_rowreq_ctx * rowreq_ctx,
                               char **ifName_val_ptr_ptr,
                               size_t *ifName_val_ptr_len_ptr);
    int             ifInMulticastPkts_get(ifXTable_rowreq_ctx * rowreq_ctx,
                                          u_long *
                                          ifInMulticastPkts_val_ptr);
    int             ifInBroadcastPkts_get(ifXTable_rowreq_ctx * rowreq_ctx,
                                          u_long *
                                          ifInBroadcastPkts_val_ptr);
    int             ifOutMulticastPkts_get(ifXTable_rowreq_ctx *
                                           rowreq_ctx,
                                           u_long *
                                           ifOutMulticastPkts_val_ptr);
    int             ifOutBroadcastPkts_get(ifXTable_rowreq_ctx *
                                           rowreq_ctx,
                                           u_long *
                                           ifOutBroadcastPkts_val_ptr);
    int             ifHCInOctets_get(ifXTable_rowreq_ctx * rowreq_ctx,
                                     U64 * ifHCInOctets_val_ptr);
    int             ifHCInUcastPkts_get(ifXTable_rowreq_ctx * rowreq_ctx,
                                        U64 * ifHCInUcastPkts_val_ptr);
    int             ifHCInMulticastPkts_get(ifXTable_rowreq_ctx *
                                            rowreq_ctx,
                                            U64 *
                                            ifHCInMulticastPkts_val_ptr);
    int             ifHCInBroadcastPkts_get(ifXTable_rowreq_ctx *
                                            rowreq_ctx,
                                            U64 *
                                            ifHCInBroadcastPkts_val_ptr);
    int             ifHCOutOctets_get(ifXTable_rowreq_ctx * rowreq_ctx,
                                      U64 * ifHCOutOctets_val_ptr);
    int             ifHCOutUcastPkts_get(ifXTable_rowreq_ctx * rowreq_ctx,
                                         U64 * ifHCOutUcastPkts_val_ptr);
    int             ifHCOutMulticastPkts_get(ifXTable_rowreq_ctx *
                                             rowreq_ctx,
                                             U64 *
                                             ifHCOutMulticastPkts_val_ptr);
    int             ifHCOutBroadcastPkts_get(ifXTable_rowreq_ctx *
                                             rowreq_ctx,
                                             U64 *
                                             ifHCOutBroadcastPkts_val_ptr);
    int             ifLinkUpDownTrapEnable_get(ifXTable_rowreq_ctx *
                                               rowreq_ctx,
                                               u_long *
                                               ifLinkUpDownTrapEnable_val_ptr);
    int             ifHighSpeed_get(ifXTable_rowreq_ctx * rowreq_ctx,
                                    u_long * ifHighSpeed_val_ptr);
    int             ifPromiscuousMode_get(ifXTable_rowreq_ctx * rowreq_ctx,
                                          u_long *
                                          ifPromiscuousMode_val_ptr);
    int             ifConnectorPresent_get(ifXTable_rowreq_ctx *
                                           rowreq_ctx,
                                           u_long *
                                           ifConnectorPresent_val_ptr);
    int             ifAlias_get(ifXTable_rowreq_ctx * rowreq_ctx,
                                char **ifAlias_val_ptr_ptr,
                                size_t *ifAlias_val_ptr_len_ptr);
    int             ifCounterDiscontinuityTime_get(ifXTable_rowreq_ctx *
                                                   rowreq_ctx,
                                                   u_long *
                                                   ifCounterDiscontinuityTime_val_ptr);


    int             ifXTable_indexes_set_tbl_idx(ifXTable_mib_index *
                                                 tbl_idx,
                                                 long ifIndex_val);
    int             ifXTable_indexes_set(ifXTable_rowreq_ctx * rowreq_ctx,
                                         long ifIndex_val);



    /*
     *********************************************************************
     * SET function declarations
     */

    /*
     *********************************************************************
     * SET Table declarations
     */
/**********************************************************************
 **********************************************************************
 ***
 *** Table ifXTable
 ***
 **********************************************************************
 **********************************************************************/
    /*
     * ifXTable is subid 1 of ifMIBObjects.
     * Its status is Current.
     * OID: .1.3.6.1.2.1.31.1.1, length: 9
     */
    int             ifXTable_ifIndex_check_index(ifXTable_rowreq_ctx * rowreq_ctx);     /* external */


    int             ifXTable_undo_setup(ifXTable_rowreq_ctx * rowreq_ctx);
    int             ifXTable_undo_cleanup(ifXTable_rowreq_ctx *
                                          rowreq_ctx);
    int             ifXTable_commit(ifXTable_rowreq_ctx * rowreq_ctx);
    int             ifXTable_undo_commit(ifXTable_rowreq_ctx * rowreq_ctx);


    int             ifName_check_value(ifXTable_rowreq_ctx * rowreq_ctx,
                                       char *ifName_val_ptr,
                                       size_t ifName_val_ptr_len);
    int             ifName_undo_setup(ifXTable_rowreq_ctx * rowreq_ctx);
    int             ifName_set(ifXTable_rowreq_ctx * rowreq_ctx,
                               char *ifName_val_ptr,
                               size_t ifName_val_ptr_len);
    int             ifName_undo(ifXTable_rowreq_ctx * rowreq_ctx);

    int             ifInMulticastPkts_check_value(ifXTable_rowreq_ctx *
                                                  rowreq_ctx,
                                                  u_long
                                                  ifInMulticastPkts_val);
    int             ifInMulticastPkts_undo_setup(ifXTable_rowreq_ctx *
                                                 rowreq_ctx);
    int             ifInMulticastPkts_set(ifXTable_rowreq_ctx * rowreq_ctx,
                                          u_long ifInMulticastPkts_val);
    int             ifInMulticastPkts_undo(ifXTable_rowreq_ctx *
                                           rowreq_ctx);

    int             ifInBroadcastPkts_check_value(ifXTable_rowreq_ctx *
                                                  rowreq_ctx,
                                                  u_long
                                                  ifInBroadcastPkts_val);
    int             ifInBroadcastPkts_undo_setup(ifXTable_rowreq_ctx *
                                                 rowreq_ctx);
    int             ifInBroadcastPkts_set(ifXTable_rowreq_ctx * rowreq_ctx,
                                          u_long ifInBroadcastPkts_val);
    int             ifInBroadcastPkts_undo(ifXTable_rowreq_ctx *
                                           rowreq_ctx);

    int             ifOutMulticastPkts_check_value(ifXTable_rowreq_ctx *
                                                   rowreq_ctx,
                                                   u_long
                                                   ifOutMulticastPkts_val);
    int             ifOutMulticastPkts_undo_setup(ifXTable_rowreq_ctx *
                                                  rowreq_ctx);
    int             ifOutMulticastPkts_set(ifXTable_rowreq_ctx *
                                           rowreq_ctx,
                                           u_long ifOutMulticastPkts_val);
    int             ifOutMulticastPkts_undo(ifXTable_rowreq_ctx *
                                            rowreq_ctx);

    int             ifOutBroadcastPkts_check_value(ifXTable_rowreq_ctx *
                                                   rowreq_ctx,
                                                   u_long
                                                   ifOutBroadcastPkts_val);
    int             ifOutBroadcastPkts_undo_setup(ifXTable_rowreq_ctx *
                                                  rowreq_ctx);
    int             ifOutBroadcastPkts_set(ifXTable_rowreq_ctx *
                                           rowreq_ctx,
                                           u_long ifOutBroadcastPkts_val);
    int             ifOutBroadcastPkts_undo(ifXTable_rowreq_ctx *
                                            rowreq_ctx);

    int             ifHCInOctets_check_value(ifXTable_rowreq_ctx *
                                             rowreq_ctx,
                                             U64 ifHCInOctets_val);
    int             ifHCInOctets_undo_setup(ifXTable_rowreq_ctx *
                                            rowreq_ctx);
    int             ifHCInOctets_set(ifXTable_rowreq_ctx * rowreq_ctx,
                                     U64 ifHCInOctets_val);
    int             ifHCInOctets_undo(ifXTable_rowreq_ctx * rowreq_ctx);

    int             ifHCInUcastPkts_check_value(ifXTable_rowreq_ctx *
                                                rowreq_ctx,
                                                U64 ifHCInUcastPkts_val);
    int             ifHCInUcastPkts_undo_setup(ifXTable_rowreq_ctx *
                                               rowreq_ctx);
    int             ifHCInUcastPkts_set(ifXTable_rowreq_ctx * rowreq_ctx,
                                        U64 ifHCInUcastPkts_val);
    int             ifHCInUcastPkts_undo(ifXTable_rowreq_ctx * rowreq_ctx);

    int             ifHCInMulticastPkts_check_value(ifXTable_rowreq_ctx *
                                                    rowreq_ctx,
                                                    U64
                                                    ifHCInMulticastPkts_val);
    int             ifHCInMulticastPkts_undo_setup(ifXTable_rowreq_ctx *
                                                   rowreq_ctx);
    int             ifHCInMulticastPkts_set(ifXTable_rowreq_ctx *
                                            rowreq_ctx,
                                            U64 ifHCInMulticastPkts_val);
    int             ifHCInMulticastPkts_undo(ifXTable_rowreq_ctx *
                                             rowreq_ctx);

    int             ifHCInBroadcastPkts_check_value(ifXTable_rowreq_ctx *
                                                    rowreq_ctx,
                                                    U64
                                                    ifHCInBroadcastPkts_val);
    int             ifHCInBroadcastPkts_undo_setup(ifXTable_rowreq_ctx *
                                                   rowreq_ctx);
    int             ifHCInBroadcastPkts_set(ifXTable_rowreq_ctx *
                                            rowreq_ctx,
                                            U64 ifHCInBroadcastPkts_val);
    int             ifHCInBroadcastPkts_undo(ifXTable_rowreq_ctx *
                                             rowreq_ctx);

    int             ifHCOutOctets_check_value(ifXTable_rowreq_ctx *
                                              rowreq_ctx,
                                              U64 ifHCOutOctets_val);
    int             ifHCOutOctets_undo_setup(ifXTable_rowreq_ctx *
                                             rowreq_ctx);
    int             ifHCOutOctets_set(ifXTable_rowreq_ctx * rowreq_ctx,
                                      U64 ifHCOutOctets_val);
    int             ifHCOutOctets_undo(ifXTable_rowreq_ctx * rowreq_ctx);

    int             ifHCOutUcastPkts_check_value(ifXTable_rowreq_ctx *
                                                 rowreq_ctx,
                                                 U64 ifHCOutUcastPkts_val);
    int             ifHCOutUcastPkts_undo_setup(ifXTable_rowreq_ctx *
                                                rowreq_ctx);
    int             ifHCOutUcastPkts_set(ifXTable_rowreq_ctx * rowreq_ctx,
                                         U64 ifHCOutUcastPkts_val);
    int             ifHCOutUcastPkts_undo(ifXTable_rowreq_ctx *
                                          rowreq_ctx);

    int             ifHCOutMulticastPkts_check_value(ifXTable_rowreq_ctx *
                                                     rowreq_ctx,
                                                     U64
                                                     ifHCOutMulticastPkts_val);
    int             ifHCOutMulticastPkts_undo_setup(ifXTable_rowreq_ctx *
                                                    rowreq_ctx);
    int             ifHCOutMulticastPkts_set(ifXTable_rowreq_ctx *
                                             rowreq_ctx,
                                             U64 ifHCOutMulticastPkts_val);
    int             ifHCOutMulticastPkts_undo(ifXTable_rowreq_ctx *
                                              rowreq_ctx);

    int             ifHCOutBroadcastPkts_check_value(ifXTable_rowreq_ctx *
                                                     rowreq_ctx,
                                                     U64
                                                     ifHCOutBroadcastPkts_val);
    int             ifHCOutBroadcastPkts_undo_setup(ifXTable_rowreq_ctx *
                                                    rowreq_ctx);
    int             ifHCOutBroadcastPkts_set(ifXTable_rowreq_ctx *
                                             rowreq_ctx,
                                             U64 ifHCOutBroadcastPkts_val);
    int             ifHCOutBroadcastPkts_undo(ifXTable_rowreq_ctx *
                                              rowreq_ctx);

    int             ifLinkUpDownTrapEnable_check_value(ifXTable_rowreq_ctx
                                                       * rowreq_ctx,
                                                       u_long
                                                       ifLinkUpDownTrapEnable_val);
    int             ifLinkUpDownTrapEnable_undo_setup(ifXTable_rowreq_ctx *
                                                      rowreq_ctx);
    int             ifLinkUpDownTrapEnable_set(ifXTable_rowreq_ctx *
                                               rowreq_ctx,
                                               u_long
                                               ifLinkUpDownTrapEnable_val);
    int             ifLinkUpDownTrapEnable_undo(ifXTable_rowreq_ctx *
                                                rowreq_ctx);

    int             ifHighSpeed_check_value(ifXTable_rowreq_ctx *
                                            rowreq_ctx,
                                            u_long ifHighSpeed_val);
    int             ifHighSpeed_undo_setup(ifXTable_rowreq_ctx *
                                           rowreq_ctx);
    int             ifHighSpeed_set(ifXTable_rowreq_ctx * rowreq_ctx,
                                    u_long ifHighSpeed_val);
    int             ifHighSpeed_undo(ifXTable_rowreq_ctx * rowreq_ctx);

    int             ifPromiscuousMode_check_value(ifXTable_rowreq_ctx *
                                                  rowreq_ctx,
                                                  u_long
                                                  ifPromiscuousMode_val);
    int             ifPromiscuousMode_undo_setup(ifXTable_rowreq_ctx *
                                                 rowreq_ctx);
    int             ifPromiscuousMode_set(ifXTable_rowreq_ctx * rowreq_ctx,
                                          u_long ifPromiscuousMode_val);
    int             ifPromiscuousMode_undo(ifXTable_rowreq_ctx *
                                           rowreq_ctx);

    int             ifConnectorPresent_check_value(ifXTable_rowreq_ctx *
                                                   rowreq_ctx,
                                                   u_long
                                                   ifConnectorPresent_val);
    int             ifConnectorPresent_undo_setup(ifXTable_rowreq_ctx *
                                                  rowreq_ctx);
    int             ifConnectorPresent_set(ifXTable_rowreq_ctx *
                                           rowreq_ctx,
                                           u_long ifConnectorPresent_val);
    int             ifConnectorPresent_undo(ifXTable_rowreq_ctx *
                                            rowreq_ctx);

    int             ifAlias_check_value(ifXTable_rowreq_ctx * rowreq_ctx,
                                        char *ifAlias_val_ptr,
                                        size_t ifAlias_val_ptr_len);
    int             ifAlias_undo_setup(ifXTable_rowreq_ctx * rowreq_ctx);
    int             ifAlias_set(ifXTable_rowreq_ctx * rowreq_ctx,
                                char *ifAlias_val_ptr,
                                size_t ifAlias_val_ptr_len);
    int             ifAlias_undo(ifXTable_rowreq_ctx * rowreq_ctx);

    int            
        ifCounterDiscontinuityTime_check_value(ifXTable_rowreq_ctx *
                                               rowreq_ctx,
                                               u_long
                                               ifCounterDiscontinuityTime_val);
    int            
        ifCounterDiscontinuityTime_undo_setup(ifXTable_rowreq_ctx *
                                              rowreq_ctx);
    int             ifCounterDiscontinuityTime_set(ifXTable_rowreq_ctx *
                                                   rowreq_ctx,
                                                   u_long
                                                   ifCounterDiscontinuityTime_val);
    int             ifCounterDiscontinuityTime_undo(ifXTable_rowreq_ctx *
                                                    rowreq_ctx);


    int             ifXTable_check_dependencies(ifXTable_rowreq_ctx * ctx);


    /*
     * DUMMY markers, ignore
     *
     * TODO:099:x: *************************************************************
     * TODO:199:x: *************************************************************
     * TODO:299:x: *************************************************************
     * TODO:399:x: *************************************************************
     * TODO:499:x: *************************************************************
     */

#ifdef __cplusplus
}
#endif
#endif                          /* IFXTABLE_H */
