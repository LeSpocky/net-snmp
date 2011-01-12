/*
 * Note: this file originally auto-generated by mib2c using
 *       version : 1.10 $ of : mfd-data-access.m2c,v $ 
 *
 * $Id$
 */
/*
 * standard Net-SNMP includes 
 */
#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>

/*
 * include our parent header 
 */
#include "ifTable.h"
#include "ifTable_data_access.h"

#include <unistd.h>
#include <net/if.h>
#include <sys/ioctl.h>

/** @defgroup data_access data_access: Routines to access data
 *
 * These routines are used to locate the data used to satisfy
 * requests.
 * 
 * @{
 */
/**********************************************************************
 **********************************************************************
 ***
 *** Table ifTable
 ***
 **********************************************************************
 **********************************************************************/
/*
 * ifTable is subid 2 of interfaces.
 * It's status is Current.
 * OID: .1.3.6.1.2.1.2.2, length: 8
 */
static const char     *scan_line_2_2 =
    "%lu %lu %lu %lu %*lu %*lu %*lu %*lu %lu %lu %lu %lu %*lu %lu";
static const char     *scan_line_2_0 =
    "%lu %lu %*lu %*lu %*lu %lu %lu %*lu %*lu %lu";
static const char     *scan_line_to_use = NULL;
static char     scan_expected;

void
_choose_proc_format(void)
{
    FILE *devin;
    char  line[MAX_LINE_SIZE];

    if (NULL != scan_line_to_use)
        return;

    if (!(devin = fopen("/proc/net/dev", "r"))) {
        snmp_log(LOG_ERR, "snmpd: cannot open /proc/net/dev\n");
        return;
    }
    /*
     * Read the first two lines of the file, containing the header
     * This indicates which version of the kernel we're working with,
     * and hence which statistics are actually available.
     */
    fgets(line, sizeof(line), devin); /* ignore first line */
    fgets(line, sizeof(line), devin);
    if (strstr(line, "compressed")) {
        scan_line_to_use = scan_line_2_2;
        scan_expected = 9;
        DEBUGMSGTL(("ifTable", "using linux 2.2 kernel /proc/net/dev\n"));
     } else {
         scan_line_to_use = scan_line_2_0;
         scan_expected = 5;
         DEBUGMSGTL(("ifTable",
                     "using linux 2.0 kernel /proc/net/dev\n"));
    }
    fclose(devin);
}

/**
 * initialization for ifTable data access
 *
 * This function is called during startup to allow you to
 * allocate any resources you need for the data table.
 *
 * @param ifTable_reg
 *        Pointer to ifTable_registration
 *
 * @retval MFD_SUCCESS : success.
 * @retval MFD_ERROR   : unrecoverable error.
 */
int
ifTable_init_data(ifTable_registration_ptr ifTable_reg)
{
    static unsigned int my_columns[] = {
        COLUMN_IFINDEX, COLUMN_IFTYPE, COLUMN_IFPHYSADDRESS,
        COLUMN_IFINOCTETS, COLUMN_IFINUCASTPKTS, COLUMN_IFMTU,
        COLUMN_IFOUTOCTETS, COLUMN_IFOUTUCASTPKTS };
    static netsnmp_column_info valid_columns;

    DEBUGMSGTL(("verbose:ifTable_init_data", "called\n"));

    /*
     ***************************************************
     ***             START EXAMPLE CODE              ***
     ***---------------------------------------------***/
    /*
     * we only want to process certain columns, and ignore
     * anything else.
     */
    valid_columns.isRange = 0;
    valid_columns.details.list = my_columns;
    valid_columns.list_count = sizeof(my_columns)/sizeof(int);
    ifTable_valid_columns_set(&valid_columns);

    _choose_proc_format();
    /*
     ***---------------------------------------------***
     ***              END  EXAMPLE CODE              ***
     ***************************************************/

    return MFD_SUCCESS;
}

/**
 * container-cached overview
 *
 */

/***********************************************************************
 *
 * cache
 *
 ***********************************************************************/
/**
 * container initialization
 *
 * @param container_ptr_ptr A pointer to a container pointer. If you
 *        create a custom container, use this parameter to return it
 *        to the MFD helper. If set to NULL, the MFD helper will
 *        allocate a container for you.
 * @param  cache A pointer to a cache structure. You can set the timeout
 *         and other cache flags using this pointer.
 *
 *  This function is called at startup to allow you to customize certain
 *  aspects of the access method. For the most part, it is for advanced
 *  users. The default code should suffice for most cases. If no custom
 *  container is allocated, the MFD code will create one for your.
 *
 *  This is also the place to set up cache behavior. The default, to
 *  simply set the cache timeout, will work well with the default
 *  container. If you are using a custom container, you may want to
 *  look at the cache helper documentation to see if there are any
 *  flags you want to set.
 *
 * @remark
 *  This would also be a good place to do any initialization needed
 *  for you data source. For example, opening a connection to another
 *  process that will supply the data, opening a database, etc.
 */
void
ifTable_container_init(netsnmp_container ** container_ptr_ptr,
                       netsnmp_cache * cache)
{
    DEBUGMSGTL(("verbose:ifTable_container_init", "called\n"));

    if ((NULL == cache) || (NULL == container_ptr_ptr)) {
        snmp_log(LOG_ERR, "bad params to ifTable_container_init\n");
        return;
    }

    /*
     * For advanced users, you can use a custom container. If you
     * do not create one, one will be created for you.
     */
    *container_ptr_ptr = NULL;

    /*
     * Also for advance users, you can set parameters for the
     * cache. Do not change the magic pointer, as it is used
     * by the MFD helper.
     */
    cache->timeout = 30;        /* seconds */

    /*
     * preload to assigne initial index values
     */
    cache->flags |= NETSNMP_CACHE_PRELOAD;
}

/**
 * load cache data
 *
 * @param container container to which items should be inserted
 *
 * @retval MFD_SUCCESS              : success.
 * @retval MFD_RESOURCE_UNAVAILABLE : Can't access data source
 * @retval MFD_ERROR                : other error.
 *
 *  This function is called to cache the index(es) (and data, optionally)
 *  for the every row in the data set.
 *
 * @remark
 *  While loading the cache, the only important thing is the indexes.
 *  If access to your data is cheap/fast (e.g. you have a pointer to a
 *  structure in memory), it would make sense to update the data here.
 *  If, however, the accessing the data invovles more work (e.g. parsing
 *  some other existing data, or peforming calculations to derive the data),
 *  then you can limit yourself to setting the indexes and saving any
 *  information you will need later. Then use the saved information in
 *  ifTable_row_prep() for populating data.
 *
 * @note
 *  If you need consistency between rows (like you want statistics
 *  for each row to be from the same time frame), you should set all
 *  data here.
 *
 */
int
ifTable_cache_load(netsnmp_container * container)
{
    ifTable_rowreq_ctx *rowreq_ctx;
    int rc = MFD_SUCCESS;

    /*
     * this example code is based on a data source that is a
     * text file to be read and parsed.
     */
    FILE           *filep;
    char            line[MAX_LINE_SIZE];
    int             fd;

    /*
     * temporary storage for index values
     */
    /*
     * ifIndex(1)/InterfaceIndex/ASN_INTEGER/long(long)//l/A/w/e/R/d/H
     */
    long            ifIndex;

    DEBUGMSGTL(("verbose:ifTable_cache_load", "called\n"));

    /*
     ***************************************************
     ***             START EXAMPLE CODE              ***
     ***---------------------------------------------***/
    /*
     * open our data file.
     */
    filep = fopen("/proc/net/dev", "r");
    if (NULL == filep) {
        return MFD_RESOURCE_UNAVAILABLE;
    }

    /*
     * create socket for ioctls
     */
    fd = socket(AF_INET, SOCK_DGRAM, 0);
    if(fd < 0) {
        fclose(filep);
        return MFD_RESOURCE_UNAVAILABLE;
    }

    /*
     * ignore header lines
     */
    fgets(line, sizeof(line), filep);
    fgets(line, sizeof(line), filep);

    /*
     ***---------------------------------------------***
     ***              END  EXAMPLE CODE              ***
     ***************************************************/
    /*
     * TODO: update container
     *
     * loop over your data, allocate, set index, insert into the container
     */
    /*
     * The rest of the file provides the statistics for an interface.
     * Read in each line in turn, isolate the interface name
     *   and retrieve (or create) the corresponding data structure.
     */
    while (1) {
        struct ifreq    ifrq;
        int             scan_count;
        char           *stats, *ifstart;
        unsigned long   rec_pkt, rec_oct, rec_err, rec_drop;
        unsigned long   snd_pkt, snd_oct, snd_err, snd_drop, coll;

        /*
         ***************************************************
         ***             START EXAMPLE CODE              ***
         ***---------------------------------------------***/
        /*
         * get a line (skip blank lines)
         */
        do {
            if (!fgets(line, sizeof(line), filep)) {
                /*
                 * we're done 
                 */
                fclose(filep);
                filep = NULL;
            }
        } while (filep && (line[0] == '\n'));

        /*
         * check for end of data
         */
        if (NULL == filep)
            break;

        /*
         * TODO: parse line
         * parse line into variables
         */
        ifstart = line;
        while (*ifstart && *ifstart == ' ')
            ifstart++;
        if ((!*ifstart) || ((stats = strrchr(ifstart, ':')) == NULL)) {
            snmp_log(LOG_ERR,
                     "interface data format error 1, line ==|%s|\n",
                     line);
            DEBUGMSGTL(("ifTable", "found '%s'\n", ifstart));
            continue;
        }

        /*
         * If we've met this interface before, use the same index.
         * Otherwise find an unused index value and use that.
         */
        *stats++ = 0; /* null terminate name */
        ifIndex = se_find_value_in_slist("interfaces", ifstart);
        if (ifIndex == SE_DNE) {
            ifIndex = se_find_free_value_in_slist("interfaces");
            if (ifIndex == SE_DNE)
                ifIndex = 1;       /* Completely new list! */
            se_add_pair_to_slist("interfaces",
                                 strdup(ifstart), ifIndex);
            DEBUGMSGTL(("ifTable:ifIndex", "new ifIndex %d for %s\n",
                        ifIndex, ifstart));
        }
        if ((NULL == ifstart) || (0 == ifIndex)) {
            rc = MFD_END_OF_DATA;
            break;
        }

        /*
         ***---------------------------------------------***
         ***              END  EXAMPLE CODE              ***
         ***************************************************/

        /*
         * allocate an row context and set the index(es)
         */
        rowreq_ctx = ifTable_allocate_rowreq_ctx();
        if (NULL == rowreq_ctx) {
            snmp_log(LOG_ERR, "memory allocation failed\n");
            return MFD_RESOURCE_UNAVAILABLE;
        }
        if (MFD_SUCCESS != ifTable_indexes_set(rowreq_ctx, ifIndex)) {
            snmp_log(LOG_ERR, "error setting index while loading "
                     "ifTable cache.\n");
            ifTable_release_rowreq_ctx(rowreq_ctx);
            continue;
        }

        rec_pkt = rec_oct = rec_err = rec_drop = 0;
        snd_pkt = snd_oct = snd_err = snd_drop = coll = 0;
        if (scan_line_to_use == scan_line_2_2) {
            scan_count = sscanf(stats, scan_line_to_use,
                                &rec_oct, &rec_pkt, &rec_err, &rec_drop,
                                &snd_oct, &snd_pkt, &snd_err, &snd_drop,
                                &coll);
        } else {
            scan_count = sscanf(stats, scan_line_to_use,
                                &rec_pkt, &rec_err,
                                &snd_pkt, &snd_err, &coll);
        }
        if(scan_count != scan_expected) {
            snmp_log(LOG_ERR,
                     "error scanning interface data (expected %d, got %d)\n",
                     scan_expected, scan_count);
            rc = MFD_ERROR;
            break;
        }
        if (scan_line_to_use != scan_line_2_2) {
            rec_oct = rec_pkt * 308;
            snd_oct = snd_pkt * 308;
        }

        /*
         * TODO: populate data context
         */
        /*
         * TRANSIENT or semi-TRANSIENT data:
         * copy data or save any info needed to do it in row_prep.
         */
        /*
         * TODO: setup/save data for ifDescr
         * ifDescr(2)/DisplayString/ASN_OCTET_STR/char(char)//L/A/w/e/R/d/H
         */
        /** no code to get description yet */
        rowreq_ctx->data.ifDescr[0] = 0;
        rowreq_ctx->data.ifDescr_len = 0;

        /*
         * TODO: setup/save data for ifMtu
         * ifMtu(4)/INTEGER32/ASN_INTEGER/long(long)//l/A/w/e/r/d/h
         */
        /*
         * TODO:
         * value mapping
         */

        /*
         * TODO: setup/save data for ifSpeed
         * ifSpeed(5)/GAUGE/ASN_GAUGE/u_long(u_long)//l/A/w/e/r/d/h
         */
        /*
         * TODO:
         * value mapping
         */

        /*
         * TODO: setup/save data for ifPhysAddress
         * ifPhysAddress(6)/PhysAddress/ASN_OCTET_STR/char(char)//L/A/w/e/r/d/H
         */
        /*
         * make sure there is enough space for data
         */
        if (sizeof(rowreq_ctx->data.ifPhysAddress) < 6) {
            snmp_log(LOG_ERR, "not enough space for address while loading "
                         "ifTable cache.\n");
            ifTable_release_rowreq_ctx(rowreq_ctx);
            continue;
        }
        rowreq_ctx->data.ifPhysAddress_len = 6;
        strncpy(ifrq.ifr_name, ifstart, sizeof(ifrq.ifr_name));
        ifrq.ifr_name[ sizeof(ifrq.ifr_name)-1 ] = 0;
        if (ioctl(fd, SIOCGIFHWADDR, &ifrq) < 0)
            memset(rowreq_ctx->data.ifPhysAddress, (0), 6);
        else {
            memcpy(rowreq_ctx->data.ifPhysAddress,
                   ifrq.ifr_hwaddr.sa_data, 6);
        }

        /*
         * TODO: setup/save data for ifType
         * ifType(3)/IANAifType/ASN_INTEGER/long(u_long)//l/A/w/E/r/d/h
         */
        /*
         * TODO:
         * value mapping
         */
        if (MFD_SUCCESS !=
            ifType_map(&rowreq_ctx->data.ifType,
                       ifrq.ifr_hwaddr.sa_family)) {
            snmp_log(LOG_ERR, "error mapping ifType while loading "
                     "ifTable cache.\n");
            ifTable_release_rowreq_ctx(rowreq_ctx);
            continue;
        }

        /*
         * TODO: setup/save data for ifAdminStatus
         * ifAdminStatus(7)/INTEGER/ASN_INTEGER/long(u_long)//l/A/W/E/r/d/h
         */
        /*
         * TODO:
         * value mapping
         */

        /*
         * TODO: setup/save data for ifOperStatus
         * ifOperStatus(8)/INTEGER/ASN_INTEGER/long(u_long)//l/A/w/E/r/d/h
         */
        /*
         * TODO:
         * value mapping
         */

        /*
         * TODO: setup/save data for ifLastChange
         * ifLastChange(9)/TICKS/ASN_TIMETICKS/u_long(u_long)//l/A/w/e/r/d/h
         */
        /*
         * TODO:
         * value mapping
         */

        /*
         * TODO: setup/save data for ifInOctets
         * ifInOctets(10)/COUNTER/ASN_COUNTER/u_long(u_long)//l/A/w/e/r/d/h
         */
        rowreq_ctx->data.ifInOctets = rec_oct;

        /*
         * TODO: setup/save data for ifInUcastPkts
         * ifInUcastPkts(11)/COUNTER/ASN_COUNTER/u_long(u_long)//l/A/w/e/r/d/h
         */
        rowreq_ctx->data.ifInUcastPkts = rec_pkt;

        /*
         * TODO: setup/save data for ifInNUcastPkts
         * ifInNUcastPkts(12)/COUNTER/ASN_COUNTER/u_long(u_long)//l/A/w/e/r/d/h
         */
        /*
         * TODO:
         * value mapping
         */

        /*
         * TODO: setup/save data for ifInDiscards
         * ifInDiscards(13)/COUNTER/ASN_COUNTER/u_long(u_long)//l/A/w/e/r/d/h
         */
        rowreq_ctx->data.ifInDiscards = rec_drop;

        /*
         * TODO: setup/save data for ifInErrors
         * ifInErrors(14)/COUNTER/ASN_COUNTER/u_long(u_long)//l/A/w/e/r/d/h
         */
        rowreq_ctx->data.ifInErrors = rec_err;

        /*
         * TODO: setup/save data for ifInUnknownProtos
         * ifInUnknownProtos(15)/COUNTER/ASN_COUNTER/u_long(u_long)//l/A/w/e/r/d/h
         */
        /*
         * TODO:
         * value mapping
         */

        /*
         * TODO: setup/save data for ifOutOctets
         * ifOutOctets(16)/COUNTER/ASN_COUNTER/u_long(u_long)//l/A/w/e/r/d/h
         */
        rowreq_ctx->data.ifOutOctets = snd_oct;

        /*
         * TODO: setup/save data for ifOutUcastPkts
         * ifOutUcastPkts(17)/COUNTER/ASN_COUNTER/u_long(u_long)//l/A/w/e/r/d/h
         */
        rowreq_ctx->data.ifOutUcastPkts = snd_pkt;

        /*
         * TODO: setup/save data for ifOutNUcastPkts
         * ifOutNUcastPkts(18)/COUNTER/ASN_COUNTER/u_long(u_long)//l/A/w/e/r/d/h
         */
        /*
         * TODO:
         * value mapping
         */

        /*
         * TODO: setup/save data for ifOutDiscards
         * ifOutDiscards(19)/COUNTER/ASN_COUNTER/u_long(u_long)//l/A/w/e/r/d/h
         */
        rowreq_ctx->data.ifOutDiscards = snd_drop;

        /*
         * TODO: setup/save data for ifOutErrors
         * ifOutErrors(20)/COUNTER/ASN_COUNTER/u_long(u_long)//l/A/w/e/r/d/h
         */
        rowreq_ctx->data.ifOutErrors = snd_err;

        /*
         * TODO: setup/save data for ifOutQLen
         * ifOutQLen(21)/GAUGE/ASN_GAUGE/u_long(u_long)//l/A/w/e/r/d/h
         */
        /*
         * TODO:
         * value mapping
         */

        /*
         * TODO: setup/save data for ifSpecific
         * ifSpecific(22)/OBJECTID/ASN_OBJECT_ID/oid(oid)//L/A/w/e/r/d/h
         */
        /*
         * TODO:
         * value mapping
         */
        /*
         * it is hard to autogenerate code for mapping types that are not simple
         * integers, so here is an idea of what you might need to do. It may
         * need some tweaking to get right. 
         */
        /*
         * NOTE: this code would replace the memcpy below.
         *
         * if(MFD_SUCCESS !=
         *    ifSpecific_map(&rowreq_ctx->data.ifSpecific, &rowreq_ctx->data.ifSpecific_len,
         *                TODO_FIND_ifSpecific, TODO_FIND_ifSpecific_len, 0)) {
         *    return MFD_ERROR;
         * }
         */
        /*
         * TODO:
         * update, replace or delete, if needed.
         */
        /*
         * make sure there is enough space for data
         */
        /** not implemented */

        /*
         * insert into table container
         */
        CONTAINER_INSERT(container, rowreq_ctx);
    }

    /*
     ***************************************************
     ***             START EXAMPLE CODE              ***
     ***---------------------------------------------***/
    close(fd);
    if (NULL != filep)
        fclose(filep);
    /*
     ***---------------------------------------------***
     ***              END  EXAMPLE CODE              ***
     ***************************************************/

    return rc;
}

/**
 * cache clean up
 *
 * @param container container with all current items
 *
 *  This optional callback is called prior to all
 *  item's being removed from the container. If you
 *  need to do any processing before that, do it here.
 *
 * @note
 *  The MFD helper will take care of releasing all the
 *  row contexts, so you don't need to worry about that.
 */
void
ifTable_cache_free(netsnmp_container * container)
{
    DEBUGMSGTL(("verbose:ifTable_cache_free", "called\n"));
}

/**
 * prepare row for processing.
 *
 *  When the agent has located the row for a request, this function is
 *  called to prepare the row for processing. If you fully populated
 *  the data context during the index setup phase, you may not need to
 *  do anything.
 *
 * @param rowreq_ctx pointer to a context.
 *
 * @retval MFD_SUCCESS     : success.
 * @retval MFD_ERROR       : other error.
 */
int
ifTable_row_prep(ifTable_rowreq_ctx * rowreq_ctx)
{
    DEBUGMSGTL(("verbose:ifTable_row_prep", "called\n"));

    netsnmp_assert(NULL != rowreq_ctx);


    return MFD_SUCCESS;
}

/** @} */