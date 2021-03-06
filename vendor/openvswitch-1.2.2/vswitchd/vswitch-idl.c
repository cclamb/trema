/* Generated automatically -- do not modify!    -*- buffer-read-only: t -*- */

#include <config.h>
#include "vswitchd/vswitch-idl.h"
#include <assert.h>
#include <limits.h>
#include "ovsdb-data.h"
#include "ovsdb-error.h"

static bool inited;


static struct ovsrec_bridge *
ovsrec_bridge_cast(const struct ovsdb_idl_row *row)
{
    return row ? CONTAINER_OF(row, struct ovsrec_bridge, header_) : NULL;
}

static struct ovsrec_capability *
ovsrec_capability_cast(const struct ovsdb_idl_row *row)
{
    return row ? CONTAINER_OF(row, struct ovsrec_capability, header_) : NULL;
}

static struct ovsrec_controller *
ovsrec_controller_cast(const struct ovsdb_idl_row *row)
{
    return row ? CONTAINER_OF(row, struct ovsrec_controller, header_) : NULL;
}

static struct ovsrec_interface *
ovsrec_interface_cast(const struct ovsdb_idl_row *row)
{
    return row ? CONTAINER_OF(row, struct ovsrec_interface, header_) : NULL;
}

static struct ovsrec_manager *
ovsrec_manager_cast(const struct ovsdb_idl_row *row)
{
    return row ? CONTAINER_OF(row, struct ovsrec_manager, header_) : NULL;
}

static struct ovsrec_mirror *
ovsrec_mirror_cast(const struct ovsdb_idl_row *row)
{
    return row ? CONTAINER_OF(row, struct ovsrec_mirror, header_) : NULL;
}

static struct ovsrec_netflow *
ovsrec_netflow_cast(const struct ovsdb_idl_row *row)
{
    return row ? CONTAINER_OF(row, struct ovsrec_netflow, header_) : NULL;
}

static struct ovsrec_open_vswitch *
ovsrec_open_vswitch_cast(const struct ovsdb_idl_row *row)
{
    return row ? CONTAINER_OF(row, struct ovsrec_open_vswitch, header_) : NULL;
}

static struct ovsrec_port *
ovsrec_port_cast(const struct ovsdb_idl_row *row)
{
    return row ? CONTAINER_OF(row, struct ovsrec_port, header_) : NULL;
}

static struct ovsrec_qos *
ovsrec_qos_cast(const struct ovsdb_idl_row *row)
{
    return row ? CONTAINER_OF(row, struct ovsrec_qos, header_) : NULL;
}

static struct ovsrec_queue *
ovsrec_queue_cast(const struct ovsdb_idl_row *row)
{
    return row ? CONTAINER_OF(row, struct ovsrec_queue, header_) : NULL;
}

static struct ovsrec_ssl *
ovsrec_ssl_cast(const struct ovsdb_idl_row *row)
{
    return row ? CONTAINER_OF(row, struct ovsrec_ssl, header_) : NULL;
}

static struct ovsrec_sflow *
ovsrec_sflow_cast(const struct ovsdb_idl_row *row)
{
    return row ? CONTAINER_OF(row, struct ovsrec_sflow, header_) : NULL;
}

/* Bridge table. */

static void
ovsrec_bridge_parse_controller(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_bridge *row = ovsrec_bridge_cast(row_);
    size_t i;

    assert(inited);
    row->controller = NULL;
    row->n_controller = 0;
    for (i = 0; i < datum->n; i++) {
        struct ovsrec_controller *keyRow = ovsrec_controller_cast(ovsdb_idl_get_row_arc(row_, &ovsrec_table_classes[OVSREC_TABLE_CONTROLLER], &datum->keys[i].uuid));
        if (keyRow) {
            if (!row->n_controller) {
                row->controller = xmalloc(datum->n * sizeof *row->controller);
            }
            row->controller[row->n_controller] = keyRow;
            row->n_controller++;
        }
    }
}

static void
ovsrec_bridge_parse_datapath_id(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_bridge *row = ovsrec_bridge_cast(row_);

    assert(inited);
    if (datum->n >= 1) {
        row->datapath_id = datum->keys[0].string;
    } else {
        row->datapath_id = NULL;
    }
}

static void
ovsrec_bridge_parse_datapath_type(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_bridge *row = ovsrec_bridge_cast(row_);

    assert(inited);
    if (datum->n >= 1) {
        row->datapath_type = datum->keys[0].string;
    } else {
        row->datapath_type = "";
    }
}

static void
ovsrec_bridge_parse_external_ids(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_bridge *row = ovsrec_bridge_cast(row_);
    size_t i;

    assert(inited);
    row->key_external_ids = NULL;
    row->value_external_ids = NULL;
    row->n_external_ids = 0;
    for (i = 0; i < datum->n; i++) {
        if (!row->n_external_ids) {
            row->key_external_ids = xmalloc(datum->n * sizeof *row->key_external_ids);
            row->value_external_ids = xmalloc(datum->n * sizeof *row->value_external_ids);
        }
        row->key_external_ids[row->n_external_ids] = datum->keys[i].string;
        row->value_external_ids[row->n_external_ids] = datum->values[i].string;
        row->n_external_ids++;
    }
}

static void
ovsrec_bridge_parse_fail_mode(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_bridge *row = ovsrec_bridge_cast(row_);

    assert(inited);
    if (datum->n >= 1) {
        row->fail_mode = datum->keys[0].string;
    } else {
        row->fail_mode = NULL;
    }
}

static void
ovsrec_bridge_parse_flood_vlans(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_bridge *row = ovsrec_bridge_cast(row_);
    size_t n = MIN(4096, datum->n);
    size_t i;

    assert(inited);
    row->flood_vlans = NULL;
    row->n_flood_vlans = 0;
    for (i = 0; i < n; i++) {
        if (!row->n_flood_vlans) {
            row->flood_vlans = xmalloc(n * sizeof *row->flood_vlans);
        }
        row->flood_vlans[row->n_flood_vlans] = datum->keys[i].integer;
        row->n_flood_vlans++;
    }
}

static void
ovsrec_bridge_parse_mirrors(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_bridge *row = ovsrec_bridge_cast(row_);
    size_t i;

    assert(inited);
    row->mirrors = NULL;
    row->n_mirrors = 0;
    for (i = 0; i < datum->n; i++) {
        struct ovsrec_mirror *keyRow = ovsrec_mirror_cast(ovsdb_idl_get_row_arc(row_, &ovsrec_table_classes[OVSREC_TABLE_MIRROR], &datum->keys[i].uuid));
        if (keyRow) {
            if (!row->n_mirrors) {
                row->mirrors = xmalloc(datum->n * sizeof *row->mirrors);
            }
            row->mirrors[row->n_mirrors] = keyRow;
            row->n_mirrors++;
        }
    }
}

static void
ovsrec_bridge_parse_name(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_bridge *row = ovsrec_bridge_cast(row_);

    assert(inited);
    if (datum->n >= 1) {
        row->name = datum->keys[0].string;
    } else {
        row->name = "";
    }
}

static void
ovsrec_bridge_parse_netflow(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_bridge *row = ovsrec_bridge_cast(row_);

    assert(inited);
    if (datum->n >= 1) {
        row->netflow = ovsrec_netflow_cast(ovsdb_idl_get_row_arc(row_, &ovsrec_table_classes[OVSREC_TABLE_NETFLOW], &datum->keys[0].uuid));
    } else {
        row->netflow = NULL;
    }
}

static void
ovsrec_bridge_parse_other_config(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_bridge *row = ovsrec_bridge_cast(row_);
    size_t i;

    assert(inited);
    row->key_other_config = NULL;
    row->value_other_config = NULL;
    row->n_other_config = 0;
    for (i = 0; i < datum->n; i++) {
        if (!row->n_other_config) {
            row->key_other_config = xmalloc(datum->n * sizeof *row->key_other_config);
            row->value_other_config = xmalloc(datum->n * sizeof *row->value_other_config);
        }
        row->key_other_config[row->n_other_config] = datum->keys[i].string;
        row->value_other_config[row->n_other_config] = datum->values[i].string;
        row->n_other_config++;
    }
}

static void
ovsrec_bridge_parse_ports(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_bridge *row = ovsrec_bridge_cast(row_);
    size_t i;

    assert(inited);
    row->ports = NULL;
    row->n_ports = 0;
    for (i = 0; i < datum->n; i++) {
        struct ovsrec_port *keyRow = ovsrec_port_cast(ovsdb_idl_get_row_arc(row_, &ovsrec_table_classes[OVSREC_TABLE_PORT], &datum->keys[i].uuid));
        if (keyRow) {
            if (!row->n_ports) {
                row->ports = xmalloc(datum->n * sizeof *row->ports);
            }
            row->ports[row->n_ports] = keyRow;
            row->n_ports++;
        }
    }
}

static void
ovsrec_bridge_parse_sflow(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_bridge *row = ovsrec_bridge_cast(row_);

    assert(inited);
    if (datum->n >= 1) {
        row->sflow = ovsrec_sflow_cast(ovsdb_idl_get_row_arc(row_, &ovsrec_table_classes[OVSREC_TABLE_SFLOW], &datum->keys[0].uuid));
    } else {
        row->sflow = NULL;
    }
}

static void
ovsrec_bridge_unparse_controller(struct ovsdb_idl_row *row_)
{
    struct ovsrec_bridge *row = ovsrec_bridge_cast(row_);

    assert(inited);
    free(row->controller);
}

static void
ovsrec_bridge_unparse_datapath_id(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
ovsrec_bridge_unparse_datapath_type(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
ovsrec_bridge_unparse_external_ids(struct ovsdb_idl_row *row_)
{
    struct ovsrec_bridge *row = ovsrec_bridge_cast(row_);

    assert(inited);
    free(row->key_external_ids);
    free(row->value_external_ids);
}

static void
ovsrec_bridge_unparse_fail_mode(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
ovsrec_bridge_unparse_flood_vlans(struct ovsdb_idl_row *row_)
{
    struct ovsrec_bridge *row = ovsrec_bridge_cast(row_);

    assert(inited);
    free(row->flood_vlans);
}

static void
ovsrec_bridge_unparse_mirrors(struct ovsdb_idl_row *row_)
{
    struct ovsrec_bridge *row = ovsrec_bridge_cast(row_);

    assert(inited);
    free(row->mirrors);
}

static void
ovsrec_bridge_unparse_name(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
ovsrec_bridge_unparse_netflow(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
ovsrec_bridge_unparse_other_config(struct ovsdb_idl_row *row_)
{
    struct ovsrec_bridge *row = ovsrec_bridge_cast(row_);

    assert(inited);
    free(row->key_other_config);
    free(row->value_other_config);
}

static void
ovsrec_bridge_unparse_ports(struct ovsdb_idl_row *row_)
{
    struct ovsrec_bridge *row = ovsrec_bridge_cast(row_);

    assert(inited);
    free(row->ports);
}

static void
ovsrec_bridge_unparse_sflow(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

const struct ovsrec_bridge *
ovsrec_bridge_first(const struct ovsdb_idl *idl)
{
    return ovsrec_bridge_cast(ovsdb_idl_first_row(idl, &ovsrec_table_classes[OVSREC_TABLE_BRIDGE]));
}

const struct ovsrec_bridge *
ovsrec_bridge_next(const struct ovsrec_bridge *row)
{
    return ovsrec_bridge_cast(ovsdb_idl_next_row(&row->header_));
}

void
ovsrec_bridge_delete(const struct ovsrec_bridge *row)
{
    ovsdb_idl_txn_delete(&row->header_);
}

struct ovsrec_bridge *
ovsrec_bridge_insert(struct ovsdb_idl_txn *txn)
{
    return ovsrec_bridge_cast(ovsdb_idl_txn_insert(txn, &ovsrec_table_classes[OVSREC_TABLE_BRIDGE], NULL));
}


void
ovsrec_bridge_verify_controller(const struct ovsrec_bridge *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_bridge_columns[OVSREC_BRIDGE_COL_CONTROLLER]);
}

void
ovsrec_bridge_verify_datapath_id(const struct ovsrec_bridge *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_bridge_columns[OVSREC_BRIDGE_COL_DATAPATH_ID]);
}

void
ovsrec_bridge_verify_datapath_type(const struct ovsrec_bridge *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_bridge_columns[OVSREC_BRIDGE_COL_DATAPATH_TYPE]);
}

void
ovsrec_bridge_verify_external_ids(const struct ovsrec_bridge *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_bridge_columns[OVSREC_BRIDGE_COL_EXTERNAL_IDS]);
}

void
ovsrec_bridge_verify_fail_mode(const struct ovsrec_bridge *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_bridge_columns[OVSREC_BRIDGE_COL_FAIL_MODE]);
}

void
ovsrec_bridge_verify_flood_vlans(const struct ovsrec_bridge *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_bridge_columns[OVSREC_BRIDGE_COL_FLOOD_VLANS]);
}

void
ovsrec_bridge_verify_mirrors(const struct ovsrec_bridge *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_bridge_columns[OVSREC_BRIDGE_COL_MIRRORS]);
}

void
ovsrec_bridge_verify_name(const struct ovsrec_bridge *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_bridge_columns[OVSREC_BRIDGE_COL_NAME]);
}

void
ovsrec_bridge_verify_netflow(const struct ovsrec_bridge *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_bridge_columns[OVSREC_BRIDGE_COL_NETFLOW]);
}

void
ovsrec_bridge_verify_other_config(const struct ovsrec_bridge *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_bridge_columns[OVSREC_BRIDGE_COL_OTHER_CONFIG]);
}

void
ovsrec_bridge_verify_ports(const struct ovsrec_bridge *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_bridge_columns[OVSREC_BRIDGE_COL_PORTS]);
}

void
ovsrec_bridge_verify_sflow(const struct ovsrec_bridge *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_bridge_columns[OVSREC_BRIDGE_COL_SFLOW]);
}

/* Returns the controller column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_UUID.
 * (This helps to avoid silent bugs if someone changes controller's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_bridge_get_controller(const struct ovsrec_bridge *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_UUID);
    return ovsdb_idl_read(&row->header_, &ovsrec_bridge_col_controller);
}

/* Returns the datapath_id column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes datapath_id's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_bridge_get_datapath_id(const struct ovsrec_bridge *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &ovsrec_bridge_col_datapath_id);
}

/* Returns the datapath_type column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes datapath_type's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_bridge_get_datapath_type(const struct ovsrec_bridge *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &ovsrec_bridge_col_datapath_type);
}

/* Returns the external_ids column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * 'value_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes external_ids's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_bridge_get_external_ids(const struct ovsrec_bridge *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED,
	enum ovsdb_atomic_type value_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_STRING);
    assert(value_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &ovsrec_bridge_col_external_ids);
}

/* Returns the fail_mode column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes fail_mode's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_bridge_get_fail_mode(const struct ovsrec_bridge *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &ovsrec_bridge_col_fail_mode);
}

/* Returns the flood_vlans column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_INTEGER.
 * (This helps to avoid silent bugs if someone changes flood_vlans's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_bridge_get_flood_vlans(const struct ovsrec_bridge *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_INTEGER);
    return ovsdb_idl_read(&row->header_, &ovsrec_bridge_col_flood_vlans);
}

/* Returns the mirrors column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_UUID.
 * (This helps to avoid silent bugs if someone changes mirrors's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_bridge_get_mirrors(const struct ovsrec_bridge *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_UUID);
    return ovsdb_idl_read(&row->header_, &ovsrec_bridge_col_mirrors);
}

/* Returns the name column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes name's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_bridge_get_name(const struct ovsrec_bridge *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &ovsrec_bridge_col_name);
}

/* Returns the netflow column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_UUID.
 * (This helps to avoid silent bugs if someone changes netflow's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_bridge_get_netflow(const struct ovsrec_bridge *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_UUID);
    return ovsdb_idl_read(&row->header_, &ovsrec_bridge_col_netflow);
}

/* Returns the other_config column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * 'value_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes other_config's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_bridge_get_other_config(const struct ovsrec_bridge *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED,
	enum ovsdb_atomic_type value_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_STRING);
    assert(value_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &ovsrec_bridge_col_other_config);
}

/* Returns the ports column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_UUID.
 * (This helps to avoid silent bugs if someone changes ports's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_bridge_get_ports(const struct ovsrec_bridge *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_UUID);
    return ovsdb_idl_read(&row->header_, &ovsrec_bridge_col_ports);
}

/* Returns the sflow column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_UUID.
 * (This helps to avoid silent bugs if someone changes sflow's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_bridge_get_sflow(const struct ovsrec_bridge *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_UUID);
    return ovsdb_idl_read(&row->header_, &ovsrec_bridge_col_sflow);
}

void
ovsrec_bridge_set_controller(const struct ovsrec_bridge *row, struct ovsrec_controller **controller, size_t n_controller)
{
    struct ovsdb_datum datum;
    size_t i;

    assert(inited);
    datum.n = n_controller;
    datum.keys = xmalloc(n_controller * sizeof *datum.keys);
    datum.values = NULL;
    for (i = 0; i < n_controller; i++) {
        datum.keys[i].uuid = controller[i]->header_.uuid;
    }
    ovsdb_datum_sort_unique(&datum, OVSDB_TYPE_UUID, OVSDB_TYPE_VOID);
    ovsdb_idl_txn_write(&row->header_, &ovsrec_bridge_columns[OVSREC_BRIDGE_COL_CONTROLLER], &datum);
}

void
ovsrec_bridge_set_datapath_id(const struct ovsrec_bridge *row, const char *datapath_id)
{
    struct ovsdb_datum datum;

    assert(inited);
    if (datapath_id) {
        datum.n = 1;
        datum.keys = xmalloc(sizeof *datum.keys);
        datum.keys[0].string = xstrdup(datapath_id);
    } else {
        datum.n = 0;
        datum.keys = NULL;
    }
    datum.values = NULL;
    ovsdb_idl_txn_write(&row->header_, &ovsrec_bridge_columns[OVSREC_BRIDGE_COL_DATAPATH_ID], &datum);
}

void
ovsrec_bridge_set_datapath_type(const struct ovsrec_bridge *row, const char *datapath_type)
{
    struct ovsdb_datum datum;

    assert(inited);
    datum.n = 1;
    datum.keys = xmalloc(sizeof *datum.keys);
    datum.keys[0].string = xstrdup(datapath_type);
    datum.values = NULL;
    ovsdb_idl_txn_write(&row->header_, &ovsrec_bridge_columns[OVSREC_BRIDGE_COL_DATAPATH_TYPE], &datum);
}

void
ovsrec_bridge_set_external_ids(const struct ovsrec_bridge *row, char **key_external_ids, char **value_external_ids, size_t n_external_ids)
{
    struct ovsdb_datum datum;
    size_t i;

    assert(inited);
    datum.n = n_external_ids;
    datum.keys = xmalloc(n_external_ids * sizeof *datum.keys);
    datum.values = xmalloc(n_external_ids * sizeof *datum.values);
    for (i = 0; i < n_external_ids; i++) {
        datum.keys[i].string = xstrdup(key_external_ids[i]);
        datum.values[i].string = xstrdup(value_external_ids[i]);
    }
    ovsdb_datum_sort_unique(&datum, OVSDB_TYPE_STRING, OVSDB_TYPE_STRING);
    ovsdb_idl_txn_write(&row->header_, &ovsrec_bridge_columns[OVSREC_BRIDGE_COL_EXTERNAL_IDS], &datum);
}

void
ovsrec_bridge_set_fail_mode(const struct ovsrec_bridge *row, const char *fail_mode)
{
    struct ovsdb_datum datum;

    assert(inited);
    if (fail_mode) {
        datum.n = 1;
        datum.keys = xmalloc(sizeof *datum.keys);
        datum.keys[0].string = xstrdup(fail_mode);
    } else {
        datum.n = 0;
        datum.keys = NULL;
    }
    datum.values = NULL;
    ovsdb_idl_txn_write(&row->header_, &ovsrec_bridge_columns[OVSREC_BRIDGE_COL_FAIL_MODE], &datum);
}

void
ovsrec_bridge_set_flood_vlans(const struct ovsrec_bridge *row, const int64_t *flood_vlans, size_t n_flood_vlans)
{
    struct ovsdb_datum datum;
    size_t i;

    assert(inited);
    datum.n = n_flood_vlans;
    datum.keys = xmalloc(n_flood_vlans * sizeof *datum.keys);
    datum.values = NULL;
    for (i = 0; i < n_flood_vlans; i++) {
        datum.keys[i].integer = flood_vlans[i];
    }
    ovsdb_datum_sort_unique(&datum, OVSDB_TYPE_INTEGER, OVSDB_TYPE_VOID);
    ovsdb_idl_txn_write(&row->header_, &ovsrec_bridge_columns[OVSREC_BRIDGE_COL_FLOOD_VLANS], &datum);
}

void
ovsrec_bridge_set_mirrors(const struct ovsrec_bridge *row, struct ovsrec_mirror **mirrors, size_t n_mirrors)
{
    struct ovsdb_datum datum;
    size_t i;

    assert(inited);
    datum.n = n_mirrors;
    datum.keys = xmalloc(n_mirrors * sizeof *datum.keys);
    datum.values = NULL;
    for (i = 0; i < n_mirrors; i++) {
        datum.keys[i].uuid = mirrors[i]->header_.uuid;
    }
    ovsdb_datum_sort_unique(&datum, OVSDB_TYPE_UUID, OVSDB_TYPE_VOID);
    ovsdb_idl_txn_write(&row->header_, &ovsrec_bridge_columns[OVSREC_BRIDGE_COL_MIRRORS], &datum);
}

void
ovsrec_bridge_set_name(const struct ovsrec_bridge *row, const char *name)
{
    struct ovsdb_datum datum;

    assert(inited);
    datum.n = 1;
    datum.keys = xmalloc(sizeof *datum.keys);
    datum.keys[0].string = xstrdup(name);
    datum.values = NULL;
    ovsdb_idl_txn_write(&row->header_, &ovsrec_bridge_columns[OVSREC_BRIDGE_COL_NAME], &datum);
}

void
ovsrec_bridge_set_netflow(const struct ovsrec_bridge *row, const struct ovsrec_netflow *netflow)
{
    struct ovsdb_datum datum;

    assert(inited);
    if (netflow) {
        datum.n = 1;
        datum.keys = xmalloc(sizeof *datum.keys);
        datum.keys[0].uuid = netflow->header_.uuid;
    } else {
        datum.n = 0;
        datum.keys = NULL;
    }
    datum.values = NULL;
    ovsdb_idl_txn_write(&row->header_, &ovsrec_bridge_columns[OVSREC_BRIDGE_COL_NETFLOW], &datum);
}

void
ovsrec_bridge_set_other_config(const struct ovsrec_bridge *row, char **key_other_config, char **value_other_config, size_t n_other_config)
{
    struct ovsdb_datum datum;
    size_t i;

    assert(inited);
    datum.n = n_other_config;
    datum.keys = xmalloc(n_other_config * sizeof *datum.keys);
    datum.values = xmalloc(n_other_config * sizeof *datum.values);
    for (i = 0; i < n_other_config; i++) {
        datum.keys[i].string = xstrdup(key_other_config[i]);
        datum.values[i].string = xstrdup(value_other_config[i]);
    }
    ovsdb_datum_sort_unique(&datum, OVSDB_TYPE_STRING, OVSDB_TYPE_STRING);
    ovsdb_idl_txn_write(&row->header_, &ovsrec_bridge_columns[OVSREC_BRIDGE_COL_OTHER_CONFIG], &datum);
}

void
ovsrec_bridge_set_ports(const struct ovsrec_bridge *row, struct ovsrec_port **ports, size_t n_ports)
{
    struct ovsdb_datum datum;
    size_t i;

    assert(inited);
    datum.n = n_ports;
    datum.keys = xmalloc(n_ports * sizeof *datum.keys);
    datum.values = NULL;
    for (i = 0; i < n_ports; i++) {
        datum.keys[i].uuid = ports[i]->header_.uuid;
    }
    ovsdb_datum_sort_unique(&datum, OVSDB_TYPE_UUID, OVSDB_TYPE_VOID);
    ovsdb_idl_txn_write(&row->header_, &ovsrec_bridge_columns[OVSREC_BRIDGE_COL_PORTS], &datum);
}

void
ovsrec_bridge_set_sflow(const struct ovsrec_bridge *row, const struct ovsrec_sflow *sflow)
{
    struct ovsdb_datum datum;

    assert(inited);
    if (sflow) {
        datum.n = 1;
        datum.keys = xmalloc(sizeof *datum.keys);
        datum.keys[0].uuid = sflow->header_.uuid;
    } else {
        datum.n = 0;
        datum.keys = NULL;
    }
    datum.values = NULL;
    ovsdb_idl_txn_write(&row->header_, &ovsrec_bridge_columns[OVSREC_BRIDGE_COL_SFLOW], &datum);
}

struct ovsdb_idl_column ovsrec_bridge_columns[OVSREC_BRIDGE_N_COLUMNS];

static void
ovsrec_bridge_columns_init(void)
{
    struct ovsdb_idl_column *c;

    /* Initialize ovsrec_bridge_col_controller. */
    c = &ovsrec_bridge_col_controller;
    c->name = "controller";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_UUID);
    c->type.key.u.uuid.refTableName = "Controller";
    c->type.key.u.uuid.refType = OVSDB_REF_STRONG;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 0;
    c->type.n_max = UINT_MAX;
    c->parse = ovsrec_bridge_parse_controller;
    c->unparse = ovsrec_bridge_unparse_controller;

    /* Initialize ovsrec_bridge_col_datapath_id. */
    c = &ovsrec_bridge_col_datapath_id;
    c->name = "datapath_id";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_STRING);
    c->type.key.u.string.minLen = 0;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 0;
    c->type.n_max = 1;
    c->parse = ovsrec_bridge_parse_datapath_id;
    c->unparse = ovsrec_bridge_unparse_datapath_id;

    /* Initialize ovsrec_bridge_col_datapath_type. */
    c = &ovsrec_bridge_col_datapath_type;
    c->name = "datapath_type";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_STRING);
    c->type.key.u.string.minLen = 0;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 1;
    c->type.n_max = 1;
    c->parse = ovsrec_bridge_parse_datapath_type;
    c->unparse = ovsrec_bridge_unparse_datapath_type;

    /* Initialize ovsrec_bridge_col_external_ids. */
    c = &ovsrec_bridge_col_external_ids;
    c->name = "external_ids";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_STRING);
    c->type.key.u.string.minLen = 0;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_STRING);
    c->type.value.u.string.minLen = 0;
    c->type.n_min = 0;
    c->type.n_max = UINT_MAX;
    c->parse = ovsrec_bridge_parse_external_ids;
    c->unparse = ovsrec_bridge_unparse_external_ids;

    /* Initialize ovsrec_bridge_col_fail_mode. */
    c = &ovsrec_bridge_col_fail_mode;
    c->name = "fail_mode";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_STRING);
    c->type.key.enum_ = xmalloc(sizeof *c->type.key.enum_);
    c->type.key.enum_->n = 2;
    c->type.key.enum_->keys = xmalloc(2 * sizeof *c->type.key.enum_->keys);
    c->type.key.enum_->keys[0].string = xstrdup("secure");
    c->type.key.enum_->keys[1].string = xstrdup("standalone");
    c->type.key.enum_->values = NULL;
    ovsdb_datum_sort_assert(c->type.key.enum_, OVSDB_TYPE_STRING);
    c->type.key.u.string.minLen = 0;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 0;
    c->type.n_max = 1;
    c->parse = ovsrec_bridge_parse_fail_mode;
    c->unparse = ovsrec_bridge_unparse_fail_mode;

    /* Initialize ovsrec_bridge_col_flood_vlans. */
    c = &ovsrec_bridge_col_flood_vlans;
    c->name = "flood_vlans";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_INTEGER);
    c->type.key.u.integer.min = INT64_C(0);
    c->type.key.u.integer.max = INT64_C(4095);
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 0;
    c->type.n_max = 4096;
    c->parse = ovsrec_bridge_parse_flood_vlans;
    c->unparse = ovsrec_bridge_unparse_flood_vlans;

    /* Initialize ovsrec_bridge_col_mirrors. */
    c = &ovsrec_bridge_col_mirrors;
    c->name = "mirrors";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_UUID);
    c->type.key.u.uuid.refTableName = "Mirror";
    c->type.key.u.uuid.refType = OVSDB_REF_STRONG;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 0;
    c->type.n_max = UINT_MAX;
    c->parse = ovsrec_bridge_parse_mirrors;
    c->unparse = ovsrec_bridge_unparse_mirrors;

    /* Initialize ovsrec_bridge_col_name. */
    c = &ovsrec_bridge_col_name;
    c->name = "name";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_STRING);
    c->type.key.u.string.minLen = 0;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 1;
    c->type.n_max = 1;
    c->parse = ovsrec_bridge_parse_name;
    c->unparse = ovsrec_bridge_unparse_name;

    /* Initialize ovsrec_bridge_col_netflow. */
    c = &ovsrec_bridge_col_netflow;
    c->name = "netflow";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_UUID);
    c->type.key.u.uuid.refTableName = "NetFlow";
    c->type.key.u.uuid.refType = OVSDB_REF_STRONG;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 0;
    c->type.n_max = 1;
    c->parse = ovsrec_bridge_parse_netflow;
    c->unparse = ovsrec_bridge_unparse_netflow;

    /* Initialize ovsrec_bridge_col_other_config. */
    c = &ovsrec_bridge_col_other_config;
    c->name = "other_config";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_STRING);
    c->type.key.u.string.minLen = 0;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_STRING);
    c->type.value.u.string.minLen = 0;
    c->type.n_min = 0;
    c->type.n_max = UINT_MAX;
    c->parse = ovsrec_bridge_parse_other_config;
    c->unparse = ovsrec_bridge_unparse_other_config;

    /* Initialize ovsrec_bridge_col_ports. */
    c = &ovsrec_bridge_col_ports;
    c->name = "ports";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_UUID);
    c->type.key.u.uuid.refTableName = "Port";
    c->type.key.u.uuid.refType = OVSDB_REF_STRONG;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 0;
    c->type.n_max = UINT_MAX;
    c->parse = ovsrec_bridge_parse_ports;
    c->unparse = ovsrec_bridge_unparse_ports;

    /* Initialize ovsrec_bridge_col_sflow. */
    c = &ovsrec_bridge_col_sflow;
    c->name = "sflow";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_UUID);
    c->type.key.u.uuid.refTableName = "sFlow";
    c->type.key.u.uuid.refType = OVSDB_REF_STRONG;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 0;
    c->type.n_max = 1;
    c->parse = ovsrec_bridge_parse_sflow;
    c->unparse = ovsrec_bridge_unparse_sflow;
}

/* Capability table. */

static void
ovsrec_capability_parse_details(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_capability *row = ovsrec_capability_cast(row_);
    size_t i;

    assert(inited);
    row->key_details = NULL;
    row->value_details = NULL;
    row->n_details = 0;
    for (i = 0; i < datum->n; i++) {
        if (!row->n_details) {
            row->key_details = xmalloc(datum->n * sizeof *row->key_details);
            row->value_details = xmalloc(datum->n * sizeof *row->value_details);
        }
        row->key_details[row->n_details] = datum->keys[i].string;
        row->value_details[row->n_details] = datum->values[i].string;
        row->n_details++;
    }
}

static void
ovsrec_capability_unparse_details(struct ovsdb_idl_row *row_)
{
    struct ovsrec_capability *row = ovsrec_capability_cast(row_);

    assert(inited);
    free(row->key_details);
    free(row->value_details);
}

const struct ovsrec_capability *
ovsrec_capability_first(const struct ovsdb_idl *idl)
{
    return ovsrec_capability_cast(ovsdb_idl_first_row(idl, &ovsrec_table_classes[OVSREC_TABLE_CAPABILITY]));
}

const struct ovsrec_capability *
ovsrec_capability_next(const struct ovsrec_capability *row)
{
    return ovsrec_capability_cast(ovsdb_idl_next_row(&row->header_));
}

void
ovsrec_capability_delete(const struct ovsrec_capability *row)
{
    ovsdb_idl_txn_delete(&row->header_);
}

struct ovsrec_capability *
ovsrec_capability_insert(struct ovsdb_idl_txn *txn)
{
    return ovsrec_capability_cast(ovsdb_idl_txn_insert(txn, &ovsrec_table_classes[OVSREC_TABLE_CAPABILITY], NULL));
}


void
ovsrec_capability_verify_details(const struct ovsrec_capability *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_capability_columns[OVSREC_CAPABILITY_COL_DETAILS]);
}

/* Returns the details column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * 'value_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes details's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_capability_get_details(const struct ovsrec_capability *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED,
	enum ovsdb_atomic_type value_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_STRING);
    assert(value_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &ovsrec_capability_col_details);
}

void
ovsrec_capability_set_details(const struct ovsrec_capability *row, char **key_details, char **value_details, size_t n_details)
{
    struct ovsdb_datum datum;
    size_t i;

    assert(inited);
    datum.n = n_details;
    datum.keys = xmalloc(n_details * sizeof *datum.keys);
    datum.values = xmalloc(n_details * sizeof *datum.values);
    for (i = 0; i < n_details; i++) {
        datum.keys[i].string = xstrdup(key_details[i]);
        datum.values[i].string = xstrdup(value_details[i]);
    }
    ovsdb_datum_sort_unique(&datum, OVSDB_TYPE_STRING, OVSDB_TYPE_STRING);
    ovsdb_idl_txn_write(&row->header_, &ovsrec_capability_columns[OVSREC_CAPABILITY_COL_DETAILS], &datum);
}

struct ovsdb_idl_column ovsrec_capability_columns[OVSREC_CAPABILITY_N_COLUMNS];

static void
ovsrec_capability_columns_init(void)
{
    struct ovsdb_idl_column *c;

    /* Initialize ovsrec_capability_col_details. */
    c = &ovsrec_capability_col_details;
    c->name = "details";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_STRING);
    c->type.key.u.string.minLen = 0;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_STRING);
    c->type.value.u.string.minLen = 0;
    c->type.n_min = 0;
    c->type.n_max = UINT_MAX;
    c->parse = ovsrec_capability_parse_details;
    c->unparse = ovsrec_capability_unparse_details;
}

/* Controller table. */

static void
ovsrec_controller_parse_connection_mode(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_controller *row = ovsrec_controller_cast(row_);

    assert(inited);
    if (datum->n >= 1) {
        row->connection_mode = datum->keys[0].string;
    } else {
        row->connection_mode = NULL;
    }
}

static void
ovsrec_controller_parse_controller_burst_limit(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_controller *row = ovsrec_controller_cast(row_);
    size_t n = MIN(1, datum->n);
    size_t i;

    assert(inited);
    row->controller_burst_limit = NULL;
    row->n_controller_burst_limit = 0;
    for (i = 0; i < n; i++) {
        if (!row->n_controller_burst_limit) {
            row->controller_burst_limit = xmalloc(n * sizeof *row->controller_burst_limit);
        }
        row->controller_burst_limit[row->n_controller_burst_limit] = datum->keys[i].integer;
        row->n_controller_burst_limit++;
    }
}

static void
ovsrec_controller_parse_controller_rate_limit(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_controller *row = ovsrec_controller_cast(row_);
    size_t n = MIN(1, datum->n);
    size_t i;

    assert(inited);
    row->controller_rate_limit = NULL;
    row->n_controller_rate_limit = 0;
    for (i = 0; i < n; i++) {
        if (!row->n_controller_rate_limit) {
            row->controller_rate_limit = xmalloc(n * sizeof *row->controller_rate_limit);
        }
        row->controller_rate_limit[row->n_controller_rate_limit] = datum->keys[i].integer;
        row->n_controller_rate_limit++;
    }
}

static void
ovsrec_controller_parse_external_ids(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_controller *row = ovsrec_controller_cast(row_);
    size_t i;

    assert(inited);
    row->key_external_ids = NULL;
    row->value_external_ids = NULL;
    row->n_external_ids = 0;
    for (i = 0; i < datum->n; i++) {
        if (!row->n_external_ids) {
            row->key_external_ids = xmalloc(datum->n * sizeof *row->key_external_ids);
            row->value_external_ids = xmalloc(datum->n * sizeof *row->value_external_ids);
        }
        row->key_external_ids[row->n_external_ids] = datum->keys[i].string;
        row->value_external_ids[row->n_external_ids] = datum->values[i].string;
        row->n_external_ids++;
    }
}

static void
ovsrec_controller_parse_inactivity_probe(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_controller *row = ovsrec_controller_cast(row_);
    size_t n = MIN(1, datum->n);
    size_t i;

    assert(inited);
    row->inactivity_probe = NULL;
    row->n_inactivity_probe = 0;
    for (i = 0; i < n; i++) {
        if (!row->n_inactivity_probe) {
            row->inactivity_probe = xmalloc(n * sizeof *row->inactivity_probe);
        }
        row->inactivity_probe[row->n_inactivity_probe] = datum->keys[i].integer;
        row->n_inactivity_probe++;
    }
}

static void
ovsrec_controller_parse_is_connected(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_controller *row = ovsrec_controller_cast(row_);

    assert(inited);
    if (datum->n >= 1) {
        row->is_connected = datum->keys[0].boolean;
    } else {
        row->is_connected = false;
    }
}

static void
ovsrec_controller_parse_local_gateway(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_controller *row = ovsrec_controller_cast(row_);

    assert(inited);
    if (datum->n >= 1) {
        row->local_gateway = datum->keys[0].string;
    } else {
        row->local_gateway = NULL;
    }
}

static void
ovsrec_controller_parse_local_ip(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_controller *row = ovsrec_controller_cast(row_);

    assert(inited);
    if (datum->n >= 1) {
        row->local_ip = datum->keys[0].string;
    } else {
        row->local_ip = NULL;
    }
}

static void
ovsrec_controller_parse_local_netmask(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_controller *row = ovsrec_controller_cast(row_);

    assert(inited);
    if (datum->n >= 1) {
        row->local_netmask = datum->keys[0].string;
    } else {
        row->local_netmask = NULL;
    }
}

static void
ovsrec_controller_parse_max_backoff(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_controller *row = ovsrec_controller_cast(row_);
    size_t n = MIN(1, datum->n);
    size_t i;

    assert(inited);
    row->max_backoff = NULL;
    row->n_max_backoff = 0;
    for (i = 0; i < n; i++) {
        if (!row->n_max_backoff) {
            row->max_backoff = xmalloc(n * sizeof *row->max_backoff);
        }
        row->max_backoff[row->n_max_backoff] = datum->keys[i].integer;
        row->n_max_backoff++;
    }
}

static void
ovsrec_controller_parse_role(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_controller *row = ovsrec_controller_cast(row_);

    assert(inited);
    if (datum->n >= 1) {
        row->role = datum->keys[0].string;
    } else {
        row->role = NULL;
    }
}

static void
ovsrec_controller_parse_status(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_controller *row = ovsrec_controller_cast(row_);
    size_t i;

    assert(inited);
    row->key_status = NULL;
    row->value_status = NULL;
    row->n_status = 0;
    for (i = 0; i < datum->n; i++) {
        if (!row->n_status) {
            row->key_status = xmalloc(datum->n * sizeof *row->key_status);
            row->value_status = xmalloc(datum->n * sizeof *row->value_status);
        }
        row->key_status[row->n_status] = datum->keys[i].string;
        row->value_status[row->n_status] = datum->values[i].string;
        row->n_status++;
    }
}

static void
ovsrec_controller_parse_target(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_controller *row = ovsrec_controller_cast(row_);

    assert(inited);
    if (datum->n >= 1) {
        row->target = datum->keys[0].string;
    } else {
        row->target = "";
    }
}

static void
ovsrec_controller_unparse_connection_mode(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
ovsrec_controller_unparse_controller_burst_limit(struct ovsdb_idl_row *row_)
{
    struct ovsrec_controller *row = ovsrec_controller_cast(row_);

    assert(inited);
    free(row->controller_burst_limit);
}

static void
ovsrec_controller_unparse_controller_rate_limit(struct ovsdb_idl_row *row_)
{
    struct ovsrec_controller *row = ovsrec_controller_cast(row_);

    assert(inited);
    free(row->controller_rate_limit);
}

static void
ovsrec_controller_unparse_external_ids(struct ovsdb_idl_row *row_)
{
    struct ovsrec_controller *row = ovsrec_controller_cast(row_);

    assert(inited);
    free(row->key_external_ids);
    free(row->value_external_ids);
}

static void
ovsrec_controller_unparse_inactivity_probe(struct ovsdb_idl_row *row_)
{
    struct ovsrec_controller *row = ovsrec_controller_cast(row_);

    assert(inited);
    free(row->inactivity_probe);
}

static void
ovsrec_controller_unparse_is_connected(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
ovsrec_controller_unparse_local_gateway(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
ovsrec_controller_unparse_local_ip(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
ovsrec_controller_unparse_local_netmask(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
ovsrec_controller_unparse_max_backoff(struct ovsdb_idl_row *row_)
{
    struct ovsrec_controller *row = ovsrec_controller_cast(row_);

    assert(inited);
    free(row->max_backoff);
}

static void
ovsrec_controller_unparse_role(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
ovsrec_controller_unparse_status(struct ovsdb_idl_row *row_)
{
    struct ovsrec_controller *row = ovsrec_controller_cast(row_);

    assert(inited);
    free(row->key_status);
    free(row->value_status);
}

static void
ovsrec_controller_unparse_target(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

const struct ovsrec_controller *
ovsrec_controller_first(const struct ovsdb_idl *idl)
{
    return ovsrec_controller_cast(ovsdb_idl_first_row(idl, &ovsrec_table_classes[OVSREC_TABLE_CONTROLLER]));
}

const struct ovsrec_controller *
ovsrec_controller_next(const struct ovsrec_controller *row)
{
    return ovsrec_controller_cast(ovsdb_idl_next_row(&row->header_));
}

void
ovsrec_controller_delete(const struct ovsrec_controller *row)
{
    ovsdb_idl_txn_delete(&row->header_);
}

struct ovsrec_controller *
ovsrec_controller_insert(struct ovsdb_idl_txn *txn)
{
    return ovsrec_controller_cast(ovsdb_idl_txn_insert(txn, &ovsrec_table_classes[OVSREC_TABLE_CONTROLLER], NULL));
}


void
ovsrec_controller_verify_connection_mode(const struct ovsrec_controller *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_controller_columns[OVSREC_CONTROLLER_COL_CONNECTION_MODE]);
}

void
ovsrec_controller_verify_controller_burst_limit(const struct ovsrec_controller *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_controller_columns[OVSREC_CONTROLLER_COL_CONTROLLER_BURST_LIMIT]);
}

void
ovsrec_controller_verify_controller_rate_limit(const struct ovsrec_controller *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_controller_columns[OVSREC_CONTROLLER_COL_CONTROLLER_RATE_LIMIT]);
}

void
ovsrec_controller_verify_external_ids(const struct ovsrec_controller *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_controller_columns[OVSREC_CONTROLLER_COL_EXTERNAL_IDS]);
}

void
ovsrec_controller_verify_inactivity_probe(const struct ovsrec_controller *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_controller_columns[OVSREC_CONTROLLER_COL_INACTIVITY_PROBE]);
}

void
ovsrec_controller_verify_is_connected(const struct ovsrec_controller *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_controller_columns[OVSREC_CONTROLLER_COL_IS_CONNECTED]);
}

void
ovsrec_controller_verify_local_gateway(const struct ovsrec_controller *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_controller_columns[OVSREC_CONTROLLER_COL_LOCAL_GATEWAY]);
}

void
ovsrec_controller_verify_local_ip(const struct ovsrec_controller *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_controller_columns[OVSREC_CONTROLLER_COL_LOCAL_IP]);
}

void
ovsrec_controller_verify_local_netmask(const struct ovsrec_controller *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_controller_columns[OVSREC_CONTROLLER_COL_LOCAL_NETMASK]);
}

void
ovsrec_controller_verify_max_backoff(const struct ovsrec_controller *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_controller_columns[OVSREC_CONTROLLER_COL_MAX_BACKOFF]);
}

void
ovsrec_controller_verify_role(const struct ovsrec_controller *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_controller_columns[OVSREC_CONTROLLER_COL_ROLE]);
}

void
ovsrec_controller_verify_status(const struct ovsrec_controller *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_controller_columns[OVSREC_CONTROLLER_COL_STATUS]);
}

void
ovsrec_controller_verify_target(const struct ovsrec_controller *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_controller_columns[OVSREC_CONTROLLER_COL_TARGET]);
}

/* Returns the connection_mode column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes connection_mode's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_controller_get_connection_mode(const struct ovsrec_controller *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &ovsrec_controller_col_connection_mode);
}

/* Returns the controller_burst_limit column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_INTEGER.
 * (This helps to avoid silent bugs if someone changes controller_burst_limit's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_controller_get_controller_burst_limit(const struct ovsrec_controller *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_INTEGER);
    return ovsdb_idl_read(&row->header_, &ovsrec_controller_col_controller_burst_limit);
}

/* Returns the controller_rate_limit column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_INTEGER.
 * (This helps to avoid silent bugs if someone changes controller_rate_limit's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_controller_get_controller_rate_limit(const struct ovsrec_controller *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_INTEGER);
    return ovsdb_idl_read(&row->header_, &ovsrec_controller_col_controller_rate_limit);
}

/* Returns the external_ids column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * 'value_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes external_ids's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_controller_get_external_ids(const struct ovsrec_controller *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED,
	enum ovsdb_atomic_type value_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_STRING);
    assert(value_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &ovsrec_controller_col_external_ids);
}

/* Returns the inactivity_probe column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_INTEGER.
 * (This helps to avoid silent bugs if someone changes inactivity_probe's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_controller_get_inactivity_probe(const struct ovsrec_controller *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_INTEGER);
    return ovsdb_idl_read(&row->header_, &ovsrec_controller_col_inactivity_probe);
}

/* Returns the is_connected column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_BOOLEAN.
 * (This helps to avoid silent bugs if someone changes is_connected's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_controller_get_is_connected(const struct ovsrec_controller *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_BOOLEAN);
    return ovsdb_idl_read(&row->header_, &ovsrec_controller_col_is_connected);
}

/* Returns the local_gateway column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes local_gateway's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_controller_get_local_gateway(const struct ovsrec_controller *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &ovsrec_controller_col_local_gateway);
}

/* Returns the local_ip column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes local_ip's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_controller_get_local_ip(const struct ovsrec_controller *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &ovsrec_controller_col_local_ip);
}

/* Returns the local_netmask column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes local_netmask's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_controller_get_local_netmask(const struct ovsrec_controller *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &ovsrec_controller_col_local_netmask);
}

/* Returns the max_backoff column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_INTEGER.
 * (This helps to avoid silent bugs if someone changes max_backoff's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_controller_get_max_backoff(const struct ovsrec_controller *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_INTEGER);
    return ovsdb_idl_read(&row->header_, &ovsrec_controller_col_max_backoff);
}

/* Returns the role column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes role's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_controller_get_role(const struct ovsrec_controller *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &ovsrec_controller_col_role);
}

/* Returns the status column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * 'value_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes status's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_controller_get_status(const struct ovsrec_controller *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED,
	enum ovsdb_atomic_type value_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_STRING);
    assert(value_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &ovsrec_controller_col_status);
}

/* Returns the target column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes target's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_controller_get_target(const struct ovsrec_controller *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &ovsrec_controller_col_target);
}

void
ovsrec_controller_set_connection_mode(const struct ovsrec_controller *row, const char *connection_mode)
{
    struct ovsdb_datum datum;

    assert(inited);
    if (connection_mode) {
        datum.n = 1;
        datum.keys = xmalloc(sizeof *datum.keys);
        datum.keys[0].string = xstrdup(connection_mode);
    } else {
        datum.n = 0;
        datum.keys = NULL;
    }
    datum.values = NULL;
    ovsdb_idl_txn_write(&row->header_, &ovsrec_controller_columns[OVSREC_CONTROLLER_COL_CONNECTION_MODE], &datum);
}

void
ovsrec_controller_set_controller_burst_limit(const struct ovsrec_controller *row, const int64_t *controller_burst_limit, size_t n_controller_burst_limit)
{
    struct ovsdb_datum datum;
    size_t i;

    assert(inited);
    datum.n = n_controller_burst_limit;
    datum.keys = xmalloc(n_controller_burst_limit * sizeof *datum.keys);
    datum.values = NULL;
    for (i = 0; i < n_controller_burst_limit; i++) {
        datum.keys[i].integer = controller_burst_limit[i];
    }
    ovsdb_datum_sort_unique(&datum, OVSDB_TYPE_INTEGER, OVSDB_TYPE_VOID);
    ovsdb_idl_txn_write(&row->header_, &ovsrec_controller_columns[OVSREC_CONTROLLER_COL_CONTROLLER_BURST_LIMIT], &datum);
}

void
ovsrec_controller_set_controller_rate_limit(const struct ovsrec_controller *row, const int64_t *controller_rate_limit, size_t n_controller_rate_limit)
{
    struct ovsdb_datum datum;
    size_t i;

    assert(inited);
    datum.n = n_controller_rate_limit;
    datum.keys = xmalloc(n_controller_rate_limit * sizeof *datum.keys);
    datum.values = NULL;
    for (i = 0; i < n_controller_rate_limit; i++) {
        datum.keys[i].integer = controller_rate_limit[i];
    }
    ovsdb_datum_sort_unique(&datum, OVSDB_TYPE_INTEGER, OVSDB_TYPE_VOID);
    ovsdb_idl_txn_write(&row->header_, &ovsrec_controller_columns[OVSREC_CONTROLLER_COL_CONTROLLER_RATE_LIMIT], &datum);
}

void
ovsrec_controller_set_external_ids(const struct ovsrec_controller *row, char **key_external_ids, char **value_external_ids, size_t n_external_ids)
{
    struct ovsdb_datum datum;
    size_t i;

    assert(inited);
    datum.n = n_external_ids;
    datum.keys = xmalloc(n_external_ids * sizeof *datum.keys);
    datum.values = xmalloc(n_external_ids * sizeof *datum.values);
    for (i = 0; i < n_external_ids; i++) {
        datum.keys[i].string = xstrdup(key_external_ids[i]);
        datum.values[i].string = xstrdup(value_external_ids[i]);
    }
    ovsdb_datum_sort_unique(&datum, OVSDB_TYPE_STRING, OVSDB_TYPE_STRING);
    ovsdb_idl_txn_write(&row->header_, &ovsrec_controller_columns[OVSREC_CONTROLLER_COL_EXTERNAL_IDS], &datum);
}

void
ovsrec_controller_set_inactivity_probe(const struct ovsrec_controller *row, const int64_t *inactivity_probe, size_t n_inactivity_probe)
{
    struct ovsdb_datum datum;
    size_t i;

    assert(inited);
    datum.n = n_inactivity_probe;
    datum.keys = xmalloc(n_inactivity_probe * sizeof *datum.keys);
    datum.values = NULL;
    for (i = 0; i < n_inactivity_probe; i++) {
        datum.keys[i].integer = inactivity_probe[i];
    }
    ovsdb_datum_sort_unique(&datum, OVSDB_TYPE_INTEGER, OVSDB_TYPE_VOID);
    ovsdb_idl_txn_write(&row->header_, &ovsrec_controller_columns[OVSREC_CONTROLLER_COL_INACTIVITY_PROBE], &datum);
}

void
ovsrec_controller_set_is_connected(const struct ovsrec_controller *row, bool is_connected)
{
    struct ovsdb_datum datum;

    assert(inited);
    datum.n = 1;
    datum.keys = xmalloc(sizeof *datum.keys);
    datum.keys[0].boolean = is_connected;
    datum.values = NULL;
    ovsdb_idl_txn_write(&row->header_, &ovsrec_controller_columns[OVSREC_CONTROLLER_COL_IS_CONNECTED], &datum);
}

void
ovsrec_controller_set_local_gateway(const struct ovsrec_controller *row, const char *local_gateway)
{
    struct ovsdb_datum datum;

    assert(inited);
    if (local_gateway) {
        datum.n = 1;
        datum.keys = xmalloc(sizeof *datum.keys);
        datum.keys[0].string = xstrdup(local_gateway);
    } else {
        datum.n = 0;
        datum.keys = NULL;
    }
    datum.values = NULL;
    ovsdb_idl_txn_write(&row->header_, &ovsrec_controller_columns[OVSREC_CONTROLLER_COL_LOCAL_GATEWAY], &datum);
}

void
ovsrec_controller_set_local_ip(const struct ovsrec_controller *row, const char *local_ip)
{
    struct ovsdb_datum datum;

    assert(inited);
    if (local_ip) {
        datum.n = 1;
        datum.keys = xmalloc(sizeof *datum.keys);
        datum.keys[0].string = xstrdup(local_ip);
    } else {
        datum.n = 0;
        datum.keys = NULL;
    }
    datum.values = NULL;
    ovsdb_idl_txn_write(&row->header_, &ovsrec_controller_columns[OVSREC_CONTROLLER_COL_LOCAL_IP], &datum);
}

void
ovsrec_controller_set_local_netmask(const struct ovsrec_controller *row, const char *local_netmask)
{
    struct ovsdb_datum datum;

    assert(inited);
    if (local_netmask) {
        datum.n = 1;
        datum.keys = xmalloc(sizeof *datum.keys);
        datum.keys[0].string = xstrdup(local_netmask);
    } else {
        datum.n = 0;
        datum.keys = NULL;
    }
    datum.values = NULL;
    ovsdb_idl_txn_write(&row->header_, &ovsrec_controller_columns[OVSREC_CONTROLLER_COL_LOCAL_NETMASK], &datum);
}

void
ovsrec_controller_set_max_backoff(const struct ovsrec_controller *row, const int64_t *max_backoff, size_t n_max_backoff)
{
    struct ovsdb_datum datum;
    size_t i;

    assert(inited);
    datum.n = n_max_backoff;
    datum.keys = xmalloc(n_max_backoff * sizeof *datum.keys);
    datum.values = NULL;
    for (i = 0; i < n_max_backoff; i++) {
        datum.keys[i].integer = max_backoff[i];
    }
    ovsdb_datum_sort_unique(&datum, OVSDB_TYPE_INTEGER, OVSDB_TYPE_VOID);
    ovsdb_idl_txn_write(&row->header_, &ovsrec_controller_columns[OVSREC_CONTROLLER_COL_MAX_BACKOFF], &datum);
}

void
ovsrec_controller_set_role(const struct ovsrec_controller *row, const char *role)
{
    struct ovsdb_datum datum;

    assert(inited);
    if (role) {
        datum.n = 1;
        datum.keys = xmalloc(sizeof *datum.keys);
        datum.keys[0].string = xstrdup(role);
    } else {
        datum.n = 0;
        datum.keys = NULL;
    }
    datum.values = NULL;
    ovsdb_idl_txn_write(&row->header_, &ovsrec_controller_columns[OVSREC_CONTROLLER_COL_ROLE], &datum);
}

void
ovsrec_controller_set_status(const struct ovsrec_controller *row, char **key_status, char **value_status, size_t n_status)
{
    struct ovsdb_datum datum;
    size_t i;

    assert(inited);
    datum.n = n_status;
    datum.keys = xmalloc(n_status * sizeof *datum.keys);
    datum.values = xmalloc(n_status * sizeof *datum.values);
    for (i = 0; i < n_status; i++) {
        datum.keys[i].string = xstrdup(key_status[i]);
        datum.values[i].string = xstrdup(value_status[i]);
    }
    ovsdb_datum_sort_unique(&datum, OVSDB_TYPE_STRING, OVSDB_TYPE_STRING);
    ovsdb_idl_txn_write(&row->header_, &ovsrec_controller_columns[OVSREC_CONTROLLER_COL_STATUS], &datum);
}

void
ovsrec_controller_set_target(const struct ovsrec_controller *row, const char *target)
{
    struct ovsdb_datum datum;

    assert(inited);
    datum.n = 1;
    datum.keys = xmalloc(sizeof *datum.keys);
    datum.keys[0].string = xstrdup(target);
    datum.values = NULL;
    ovsdb_idl_txn_write(&row->header_, &ovsrec_controller_columns[OVSREC_CONTROLLER_COL_TARGET], &datum);
}

struct ovsdb_idl_column ovsrec_controller_columns[OVSREC_CONTROLLER_N_COLUMNS];

static void
ovsrec_controller_columns_init(void)
{
    struct ovsdb_idl_column *c;

    /* Initialize ovsrec_controller_col_connection_mode. */
    c = &ovsrec_controller_col_connection_mode;
    c->name = "connection_mode";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_STRING);
    c->type.key.enum_ = xmalloc(sizeof *c->type.key.enum_);
    c->type.key.enum_->n = 2;
    c->type.key.enum_->keys = xmalloc(2 * sizeof *c->type.key.enum_->keys);
    c->type.key.enum_->keys[0].string = xstrdup("in-band");
    c->type.key.enum_->keys[1].string = xstrdup("out-of-band");
    c->type.key.enum_->values = NULL;
    ovsdb_datum_sort_assert(c->type.key.enum_, OVSDB_TYPE_STRING);
    c->type.key.u.string.minLen = 0;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 0;
    c->type.n_max = 1;
    c->parse = ovsrec_controller_parse_connection_mode;
    c->unparse = ovsrec_controller_unparse_connection_mode;

    /* Initialize ovsrec_controller_col_controller_burst_limit. */
    c = &ovsrec_controller_col_controller_burst_limit;
    c->name = "controller_burst_limit";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_INTEGER);
    c->type.key.u.integer.min = INT64_C(25);
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 0;
    c->type.n_max = 1;
    c->parse = ovsrec_controller_parse_controller_burst_limit;
    c->unparse = ovsrec_controller_unparse_controller_burst_limit;

    /* Initialize ovsrec_controller_col_controller_rate_limit. */
    c = &ovsrec_controller_col_controller_rate_limit;
    c->name = "controller_rate_limit";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_INTEGER);
    c->type.key.u.integer.min = INT64_C(100);
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 0;
    c->type.n_max = 1;
    c->parse = ovsrec_controller_parse_controller_rate_limit;
    c->unparse = ovsrec_controller_unparse_controller_rate_limit;

    /* Initialize ovsrec_controller_col_external_ids. */
    c = &ovsrec_controller_col_external_ids;
    c->name = "external_ids";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_STRING);
    c->type.key.u.string.minLen = 0;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_STRING);
    c->type.value.u.string.minLen = 0;
    c->type.n_min = 0;
    c->type.n_max = UINT_MAX;
    c->parse = ovsrec_controller_parse_external_ids;
    c->unparse = ovsrec_controller_unparse_external_ids;

    /* Initialize ovsrec_controller_col_inactivity_probe. */
    c = &ovsrec_controller_col_inactivity_probe;
    c->name = "inactivity_probe";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_INTEGER);
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 0;
    c->type.n_max = 1;
    c->parse = ovsrec_controller_parse_inactivity_probe;
    c->unparse = ovsrec_controller_unparse_inactivity_probe;

    /* Initialize ovsrec_controller_col_is_connected. */
    c = &ovsrec_controller_col_is_connected;
    c->name = "is_connected";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_BOOLEAN);
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 1;
    c->type.n_max = 1;
    c->parse = ovsrec_controller_parse_is_connected;
    c->unparse = ovsrec_controller_unparse_is_connected;

    /* Initialize ovsrec_controller_col_local_gateway. */
    c = &ovsrec_controller_col_local_gateway;
    c->name = "local_gateway";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_STRING);
    c->type.key.u.string.minLen = 0;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 0;
    c->type.n_max = 1;
    c->parse = ovsrec_controller_parse_local_gateway;
    c->unparse = ovsrec_controller_unparse_local_gateway;

    /* Initialize ovsrec_controller_col_local_ip. */
    c = &ovsrec_controller_col_local_ip;
    c->name = "local_ip";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_STRING);
    c->type.key.u.string.minLen = 0;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 0;
    c->type.n_max = 1;
    c->parse = ovsrec_controller_parse_local_ip;
    c->unparse = ovsrec_controller_unparse_local_ip;

    /* Initialize ovsrec_controller_col_local_netmask. */
    c = &ovsrec_controller_col_local_netmask;
    c->name = "local_netmask";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_STRING);
    c->type.key.u.string.minLen = 0;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 0;
    c->type.n_max = 1;
    c->parse = ovsrec_controller_parse_local_netmask;
    c->unparse = ovsrec_controller_unparse_local_netmask;

    /* Initialize ovsrec_controller_col_max_backoff. */
    c = &ovsrec_controller_col_max_backoff;
    c->name = "max_backoff";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_INTEGER);
    c->type.key.u.integer.min = INT64_C(1000);
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 0;
    c->type.n_max = 1;
    c->parse = ovsrec_controller_parse_max_backoff;
    c->unparse = ovsrec_controller_unparse_max_backoff;

    /* Initialize ovsrec_controller_col_role. */
    c = &ovsrec_controller_col_role;
    c->name = "role";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_STRING);
    c->type.key.enum_ = xmalloc(sizeof *c->type.key.enum_);
    c->type.key.enum_->n = 3;
    c->type.key.enum_->keys = xmalloc(3 * sizeof *c->type.key.enum_->keys);
    c->type.key.enum_->keys[0].string = xstrdup("master");
    c->type.key.enum_->keys[1].string = xstrdup("other");
    c->type.key.enum_->keys[2].string = xstrdup("slave");
    c->type.key.enum_->values = NULL;
    ovsdb_datum_sort_assert(c->type.key.enum_, OVSDB_TYPE_STRING);
    c->type.key.u.string.minLen = 0;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 0;
    c->type.n_max = 1;
    c->parse = ovsrec_controller_parse_role;
    c->unparse = ovsrec_controller_unparse_role;

    /* Initialize ovsrec_controller_col_status. */
    c = &ovsrec_controller_col_status;
    c->name = "status";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_STRING);
    c->type.key.u.string.minLen = 0;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_STRING);
    c->type.value.u.string.minLen = 0;
    c->type.n_min = 0;
    c->type.n_max = UINT_MAX;
    c->parse = ovsrec_controller_parse_status;
    c->unparse = ovsrec_controller_unparse_status;

    /* Initialize ovsrec_controller_col_target. */
    c = &ovsrec_controller_col_target;
    c->name = "target";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_STRING);
    c->type.key.u.string.minLen = 0;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 1;
    c->type.n_max = 1;
    c->parse = ovsrec_controller_parse_target;
    c->unparse = ovsrec_controller_unparse_target;
}

/* Interface table. */

static void
ovsrec_interface_parse_admin_state(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_interface *row = ovsrec_interface_cast(row_);

    assert(inited);
    if (datum->n >= 1) {
        row->admin_state = datum->keys[0].string;
    } else {
        row->admin_state = NULL;
    }
}

static void
ovsrec_interface_parse_cfm_fault(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_interface *row = ovsrec_interface_cast(row_);

    assert(inited);
    if (datum->n >= 1) {
        static const bool false_value = false;
        static const bool true_value = true;

        row->n_cfm_fault = 1;
        row->cfm_fault = datum->keys[0].boolean ? &true_value : &false_value;
    } else {
        row->n_cfm_fault = 0;
        row->cfm_fault = NULL;
    }
}

static void
ovsrec_interface_parse_cfm_mpid(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_interface *row = ovsrec_interface_cast(row_);
    size_t n = MIN(1, datum->n);
    size_t i;

    assert(inited);
    row->cfm_mpid = NULL;
    row->n_cfm_mpid = 0;
    for (i = 0; i < n; i++) {
        if (!row->n_cfm_mpid) {
            row->cfm_mpid = xmalloc(n * sizeof *row->cfm_mpid);
        }
        row->cfm_mpid[row->n_cfm_mpid] = datum->keys[i].integer;
        row->n_cfm_mpid++;
    }
}

static void
ovsrec_interface_parse_cfm_remote_mpid(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_interface *row = ovsrec_interface_cast(row_);
    size_t n = MIN(1, datum->n);
    size_t i;

    assert(inited);
    row->cfm_remote_mpid = NULL;
    row->n_cfm_remote_mpid = 0;
    for (i = 0; i < n; i++) {
        if (!row->n_cfm_remote_mpid) {
            row->cfm_remote_mpid = xmalloc(n * sizeof *row->cfm_remote_mpid);
        }
        row->cfm_remote_mpid[row->n_cfm_remote_mpid] = datum->keys[i].integer;
        row->n_cfm_remote_mpid++;
    }
}

static void
ovsrec_interface_parse_duplex(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_interface *row = ovsrec_interface_cast(row_);

    assert(inited);
    if (datum->n >= 1) {
        row->duplex = datum->keys[0].string;
    } else {
        row->duplex = NULL;
    }
}

static void
ovsrec_interface_parse_external_ids(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_interface *row = ovsrec_interface_cast(row_);
    size_t i;

    assert(inited);
    row->key_external_ids = NULL;
    row->value_external_ids = NULL;
    row->n_external_ids = 0;
    for (i = 0; i < datum->n; i++) {
        if (!row->n_external_ids) {
            row->key_external_ids = xmalloc(datum->n * sizeof *row->key_external_ids);
            row->value_external_ids = xmalloc(datum->n * sizeof *row->value_external_ids);
        }
        row->key_external_ids[row->n_external_ids] = datum->keys[i].string;
        row->value_external_ids[row->n_external_ids] = datum->values[i].string;
        row->n_external_ids++;
    }
}

static void
ovsrec_interface_parse_ingress_policing_burst(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_interface *row = ovsrec_interface_cast(row_);

    assert(inited);
    if (datum->n >= 1) {
        row->ingress_policing_burst = datum->keys[0].integer;
    } else {
        row->ingress_policing_burst = 0;
    }
}

static void
ovsrec_interface_parse_ingress_policing_rate(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_interface *row = ovsrec_interface_cast(row_);

    assert(inited);
    if (datum->n >= 1) {
        row->ingress_policing_rate = datum->keys[0].integer;
    } else {
        row->ingress_policing_rate = 0;
    }
}

static void
ovsrec_interface_parse_lacp_current(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_interface *row = ovsrec_interface_cast(row_);

    assert(inited);
    if (datum->n >= 1) {
        static const bool false_value = false;
        static const bool true_value = true;

        row->n_lacp_current = 1;
        row->lacp_current = datum->keys[0].boolean ? &true_value : &false_value;
    } else {
        row->n_lacp_current = 0;
        row->lacp_current = NULL;
    }
}

static void
ovsrec_interface_parse_link_speed(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_interface *row = ovsrec_interface_cast(row_);
    size_t n = MIN(1, datum->n);
    size_t i;

    assert(inited);
    row->link_speed = NULL;
    row->n_link_speed = 0;
    for (i = 0; i < n; i++) {
        if (!row->n_link_speed) {
            row->link_speed = xmalloc(n * sizeof *row->link_speed);
        }
        row->link_speed[row->n_link_speed] = datum->keys[i].integer;
        row->n_link_speed++;
    }
}

static void
ovsrec_interface_parse_link_state(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_interface *row = ovsrec_interface_cast(row_);

    assert(inited);
    if (datum->n >= 1) {
        row->link_state = datum->keys[0].string;
    } else {
        row->link_state = NULL;
    }
}

static void
ovsrec_interface_parse_mac(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_interface *row = ovsrec_interface_cast(row_);

    assert(inited);
    if (datum->n >= 1) {
        row->mac = datum->keys[0].string;
    } else {
        row->mac = NULL;
    }
}

static void
ovsrec_interface_parse_mtu(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_interface *row = ovsrec_interface_cast(row_);
    size_t n = MIN(1, datum->n);
    size_t i;

    assert(inited);
    row->mtu = NULL;
    row->n_mtu = 0;
    for (i = 0; i < n; i++) {
        if (!row->n_mtu) {
            row->mtu = xmalloc(n * sizeof *row->mtu);
        }
        row->mtu[row->n_mtu] = datum->keys[i].integer;
        row->n_mtu++;
    }
}

static void
ovsrec_interface_parse_name(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_interface *row = ovsrec_interface_cast(row_);

    assert(inited);
    if (datum->n >= 1) {
        row->name = datum->keys[0].string;
    } else {
        row->name = "";
    }
}

static void
ovsrec_interface_parse_ofport(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_interface *row = ovsrec_interface_cast(row_);
    size_t n = MIN(1, datum->n);
    size_t i;

    assert(inited);
    row->ofport = NULL;
    row->n_ofport = 0;
    for (i = 0; i < n; i++) {
        if (!row->n_ofport) {
            row->ofport = xmalloc(n * sizeof *row->ofport);
        }
        row->ofport[row->n_ofport] = datum->keys[i].integer;
        row->n_ofport++;
    }
}

static void
ovsrec_interface_parse_options(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_interface *row = ovsrec_interface_cast(row_);
    size_t i;

    assert(inited);
    row->key_options = NULL;
    row->value_options = NULL;
    row->n_options = 0;
    for (i = 0; i < datum->n; i++) {
        if (!row->n_options) {
            row->key_options = xmalloc(datum->n * sizeof *row->key_options);
            row->value_options = xmalloc(datum->n * sizeof *row->value_options);
        }
        row->key_options[row->n_options] = datum->keys[i].string;
        row->value_options[row->n_options] = datum->values[i].string;
        row->n_options++;
    }
}

static void
ovsrec_interface_parse_other_config(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_interface *row = ovsrec_interface_cast(row_);
    size_t i;

    assert(inited);
    row->key_other_config = NULL;
    row->value_other_config = NULL;
    row->n_other_config = 0;
    for (i = 0; i < datum->n; i++) {
        if (!row->n_other_config) {
            row->key_other_config = xmalloc(datum->n * sizeof *row->key_other_config);
            row->value_other_config = xmalloc(datum->n * sizeof *row->value_other_config);
        }
        row->key_other_config[row->n_other_config] = datum->keys[i].string;
        row->value_other_config[row->n_other_config] = datum->values[i].string;
        row->n_other_config++;
    }
}

static void
ovsrec_interface_parse_statistics(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_interface *row = ovsrec_interface_cast(row_);
    size_t i;

    assert(inited);
    row->key_statistics = NULL;
    row->value_statistics = NULL;
    row->n_statistics = 0;
    for (i = 0; i < datum->n; i++) {
        if (!row->n_statistics) {
            row->key_statistics = xmalloc(datum->n * sizeof *row->key_statistics);
            row->value_statistics = xmalloc(datum->n * sizeof *row->value_statistics);
        }
        row->key_statistics[row->n_statistics] = datum->keys[i].string;
        row->value_statistics[row->n_statistics] = datum->values[i].integer;
        row->n_statistics++;
    }
}

static void
ovsrec_interface_parse_status(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_interface *row = ovsrec_interface_cast(row_);
    size_t i;

    assert(inited);
    row->key_status = NULL;
    row->value_status = NULL;
    row->n_status = 0;
    for (i = 0; i < datum->n; i++) {
        if (!row->n_status) {
            row->key_status = xmalloc(datum->n * sizeof *row->key_status);
            row->value_status = xmalloc(datum->n * sizeof *row->value_status);
        }
        row->key_status[row->n_status] = datum->keys[i].string;
        row->value_status[row->n_status] = datum->values[i].string;
        row->n_status++;
    }
}

static void
ovsrec_interface_parse_type(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_interface *row = ovsrec_interface_cast(row_);

    assert(inited);
    if (datum->n >= 1) {
        row->type = datum->keys[0].string;
    } else {
        row->type = "";
    }
}

static void
ovsrec_interface_unparse_admin_state(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
ovsrec_interface_unparse_cfm_fault(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
ovsrec_interface_unparse_cfm_mpid(struct ovsdb_idl_row *row_)
{
    struct ovsrec_interface *row = ovsrec_interface_cast(row_);

    assert(inited);
    free(row->cfm_mpid);
}

static void
ovsrec_interface_unparse_cfm_remote_mpid(struct ovsdb_idl_row *row_)
{
    struct ovsrec_interface *row = ovsrec_interface_cast(row_);

    assert(inited);
    free(row->cfm_remote_mpid);
}

static void
ovsrec_interface_unparse_duplex(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
ovsrec_interface_unparse_external_ids(struct ovsdb_idl_row *row_)
{
    struct ovsrec_interface *row = ovsrec_interface_cast(row_);

    assert(inited);
    free(row->key_external_ids);
    free(row->value_external_ids);
}

static void
ovsrec_interface_unparse_ingress_policing_burst(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
ovsrec_interface_unparse_ingress_policing_rate(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
ovsrec_interface_unparse_lacp_current(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
ovsrec_interface_unparse_link_speed(struct ovsdb_idl_row *row_)
{
    struct ovsrec_interface *row = ovsrec_interface_cast(row_);

    assert(inited);
    free(row->link_speed);
}

static void
ovsrec_interface_unparse_link_state(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
ovsrec_interface_unparse_mac(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
ovsrec_interface_unparse_mtu(struct ovsdb_idl_row *row_)
{
    struct ovsrec_interface *row = ovsrec_interface_cast(row_);

    assert(inited);
    free(row->mtu);
}

static void
ovsrec_interface_unparse_name(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
ovsrec_interface_unparse_ofport(struct ovsdb_idl_row *row_)
{
    struct ovsrec_interface *row = ovsrec_interface_cast(row_);

    assert(inited);
    free(row->ofport);
}

static void
ovsrec_interface_unparse_options(struct ovsdb_idl_row *row_)
{
    struct ovsrec_interface *row = ovsrec_interface_cast(row_);

    assert(inited);
    free(row->key_options);
    free(row->value_options);
}

static void
ovsrec_interface_unparse_other_config(struct ovsdb_idl_row *row_)
{
    struct ovsrec_interface *row = ovsrec_interface_cast(row_);

    assert(inited);
    free(row->key_other_config);
    free(row->value_other_config);
}

static void
ovsrec_interface_unparse_statistics(struct ovsdb_idl_row *row_)
{
    struct ovsrec_interface *row = ovsrec_interface_cast(row_);

    assert(inited);
    free(row->key_statistics);
    free(row->value_statistics);
}

static void
ovsrec_interface_unparse_status(struct ovsdb_idl_row *row_)
{
    struct ovsrec_interface *row = ovsrec_interface_cast(row_);

    assert(inited);
    free(row->key_status);
    free(row->value_status);
}

static void
ovsrec_interface_unparse_type(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

const struct ovsrec_interface *
ovsrec_interface_first(const struct ovsdb_idl *idl)
{
    return ovsrec_interface_cast(ovsdb_idl_first_row(idl, &ovsrec_table_classes[OVSREC_TABLE_INTERFACE]));
}

const struct ovsrec_interface *
ovsrec_interface_next(const struct ovsrec_interface *row)
{
    return ovsrec_interface_cast(ovsdb_idl_next_row(&row->header_));
}

void
ovsrec_interface_delete(const struct ovsrec_interface *row)
{
    ovsdb_idl_txn_delete(&row->header_);
}

struct ovsrec_interface *
ovsrec_interface_insert(struct ovsdb_idl_txn *txn)
{
    return ovsrec_interface_cast(ovsdb_idl_txn_insert(txn, &ovsrec_table_classes[OVSREC_TABLE_INTERFACE], NULL));
}


void
ovsrec_interface_verify_admin_state(const struct ovsrec_interface *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_interface_columns[OVSREC_INTERFACE_COL_ADMIN_STATE]);
}

void
ovsrec_interface_verify_cfm_fault(const struct ovsrec_interface *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_interface_columns[OVSREC_INTERFACE_COL_CFM_FAULT]);
}

void
ovsrec_interface_verify_cfm_mpid(const struct ovsrec_interface *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_interface_columns[OVSREC_INTERFACE_COL_CFM_MPID]);
}

void
ovsrec_interface_verify_cfm_remote_mpid(const struct ovsrec_interface *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_interface_columns[OVSREC_INTERFACE_COL_CFM_REMOTE_MPID]);
}

void
ovsrec_interface_verify_duplex(const struct ovsrec_interface *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_interface_columns[OVSREC_INTERFACE_COL_DUPLEX]);
}

void
ovsrec_interface_verify_external_ids(const struct ovsrec_interface *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_interface_columns[OVSREC_INTERFACE_COL_EXTERNAL_IDS]);
}

void
ovsrec_interface_verify_ingress_policing_burst(const struct ovsrec_interface *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_interface_columns[OVSREC_INTERFACE_COL_INGRESS_POLICING_BURST]);
}

void
ovsrec_interface_verify_ingress_policing_rate(const struct ovsrec_interface *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_interface_columns[OVSREC_INTERFACE_COL_INGRESS_POLICING_RATE]);
}

void
ovsrec_interface_verify_lacp_current(const struct ovsrec_interface *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_interface_columns[OVSREC_INTERFACE_COL_LACP_CURRENT]);
}

void
ovsrec_interface_verify_link_speed(const struct ovsrec_interface *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_interface_columns[OVSREC_INTERFACE_COL_LINK_SPEED]);
}

void
ovsrec_interface_verify_link_state(const struct ovsrec_interface *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_interface_columns[OVSREC_INTERFACE_COL_LINK_STATE]);
}

void
ovsrec_interface_verify_mac(const struct ovsrec_interface *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_interface_columns[OVSREC_INTERFACE_COL_MAC]);
}

void
ovsrec_interface_verify_mtu(const struct ovsrec_interface *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_interface_columns[OVSREC_INTERFACE_COL_MTU]);
}

void
ovsrec_interface_verify_name(const struct ovsrec_interface *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_interface_columns[OVSREC_INTERFACE_COL_NAME]);
}

void
ovsrec_interface_verify_ofport(const struct ovsrec_interface *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_interface_columns[OVSREC_INTERFACE_COL_OFPORT]);
}

void
ovsrec_interface_verify_options(const struct ovsrec_interface *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_interface_columns[OVSREC_INTERFACE_COL_OPTIONS]);
}

void
ovsrec_interface_verify_other_config(const struct ovsrec_interface *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_interface_columns[OVSREC_INTERFACE_COL_OTHER_CONFIG]);
}

void
ovsrec_interface_verify_statistics(const struct ovsrec_interface *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_interface_columns[OVSREC_INTERFACE_COL_STATISTICS]);
}

void
ovsrec_interface_verify_status(const struct ovsrec_interface *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_interface_columns[OVSREC_INTERFACE_COL_STATUS]);
}

void
ovsrec_interface_verify_type(const struct ovsrec_interface *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_interface_columns[OVSREC_INTERFACE_COL_TYPE]);
}

/* Returns the admin_state column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes admin_state's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_interface_get_admin_state(const struct ovsrec_interface *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &ovsrec_interface_col_admin_state);
}

/* Returns the cfm_fault column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_BOOLEAN.
 * (This helps to avoid silent bugs if someone changes cfm_fault's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_interface_get_cfm_fault(const struct ovsrec_interface *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_BOOLEAN);
    return ovsdb_idl_read(&row->header_, &ovsrec_interface_col_cfm_fault);
}

/* Returns the cfm_mpid column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_INTEGER.
 * (This helps to avoid silent bugs if someone changes cfm_mpid's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_interface_get_cfm_mpid(const struct ovsrec_interface *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_INTEGER);
    return ovsdb_idl_read(&row->header_, &ovsrec_interface_col_cfm_mpid);
}

/* Returns the cfm_remote_mpid column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_INTEGER.
 * (This helps to avoid silent bugs if someone changes cfm_remote_mpid's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_interface_get_cfm_remote_mpid(const struct ovsrec_interface *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_INTEGER);
    return ovsdb_idl_read(&row->header_, &ovsrec_interface_col_cfm_remote_mpid);
}

/* Returns the duplex column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes duplex's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_interface_get_duplex(const struct ovsrec_interface *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &ovsrec_interface_col_duplex);
}

/* Returns the external_ids column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * 'value_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes external_ids's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_interface_get_external_ids(const struct ovsrec_interface *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED,
	enum ovsdb_atomic_type value_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_STRING);
    assert(value_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &ovsrec_interface_col_external_ids);
}

/* Returns the ingress_policing_burst column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_INTEGER.
 * (This helps to avoid silent bugs if someone changes ingress_policing_burst's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_interface_get_ingress_policing_burst(const struct ovsrec_interface *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_INTEGER);
    return ovsdb_idl_read(&row->header_, &ovsrec_interface_col_ingress_policing_burst);
}

/* Returns the ingress_policing_rate column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_INTEGER.
 * (This helps to avoid silent bugs if someone changes ingress_policing_rate's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_interface_get_ingress_policing_rate(const struct ovsrec_interface *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_INTEGER);
    return ovsdb_idl_read(&row->header_, &ovsrec_interface_col_ingress_policing_rate);
}

/* Returns the lacp_current column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_BOOLEAN.
 * (This helps to avoid silent bugs if someone changes lacp_current's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_interface_get_lacp_current(const struct ovsrec_interface *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_BOOLEAN);
    return ovsdb_idl_read(&row->header_, &ovsrec_interface_col_lacp_current);
}

/* Returns the link_speed column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_INTEGER.
 * (This helps to avoid silent bugs if someone changes link_speed's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_interface_get_link_speed(const struct ovsrec_interface *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_INTEGER);
    return ovsdb_idl_read(&row->header_, &ovsrec_interface_col_link_speed);
}

/* Returns the link_state column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes link_state's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_interface_get_link_state(const struct ovsrec_interface *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &ovsrec_interface_col_link_state);
}

/* Returns the mac column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes mac's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_interface_get_mac(const struct ovsrec_interface *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &ovsrec_interface_col_mac);
}

/* Returns the mtu column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_INTEGER.
 * (This helps to avoid silent bugs if someone changes mtu's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_interface_get_mtu(const struct ovsrec_interface *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_INTEGER);
    return ovsdb_idl_read(&row->header_, &ovsrec_interface_col_mtu);
}

/* Returns the name column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes name's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_interface_get_name(const struct ovsrec_interface *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &ovsrec_interface_col_name);
}

/* Returns the ofport column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_INTEGER.
 * (This helps to avoid silent bugs if someone changes ofport's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_interface_get_ofport(const struct ovsrec_interface *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_INTEGER);
    return ovsdb_idl_read(&row->header_, &ovsrec_interface_col_ofport);
}

/* Returns the options column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * 'value_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes options's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_interface_get_options(const struct ovsrec_interface *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED,
	enum ovsdb_atomic_type value_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_STRING);
    assert(value_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &ovsrec_interface_col_options);
}

/* Returns the other_config column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * 'value_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes other_config's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_interface_get_other_config(const struct ovsrec_interface *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED,
	enum ovsdb_atomic_type value_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_STRING);
    assert(value_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &ovsrec_interface_col_other_config);
}

/* Returns the statistics column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * 'value_type' must be OVSDB_TYPE_INTEGER.
 * (This helps to avoid silent bugs if someone changes statistics's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_interface_get_statistics(const struct ovsrec_interface *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED,
	enum ovsdb_atomic_type value_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_STRING);
    assert(value_type == OVSDB_TYPE_INTEGER);
    return ovsdb_idl_read(&row->header_, &ovsrec_interface_col_statistics);
}

/* Returns the status column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * 'value_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes status's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_interface_get_status(const struct ovsrec_interface *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED,
	enum ovsdb_atomic_type value_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_STRING);
    assert(value_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &ovsrec_interface_col_status);
}

/* Returns the type column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes type's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_interface_get_type(const struct ovsrec_interface *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &ovsrec_interface_col_type);
}

void
ovsrec_interface_set_admin_state(const struct ovsrec_interface *row, const char *admin_state)
{
    struct ovsdb_datum datum;

    assert(inited);
    if (admin_state) {
        datum.n = 1;
        datum.keys = xmalloc(sizeof *datum.keys);
        datum.keys[0].string = xstrdup(admin_state);
    } else {
        datum.n = 0;
        datum.keys = NULL;
    }
    datum.values = NULL;
    ovsdb_idl_txn_write(&row->header_, &ovsrec_interface_columns[OVSREC_INTERFACE_COL_ADMIN_STATE], &datum);
}

void
ovsrec_interface_set_cfm_fault(const struct ovsrec_interface *row, const bool *cfm_fault, size_t n_cfm_fault)
{
    struct ovsdb_datum datum;
    size_t i;

    assert(inited);
    datum.n = n_cfm_fault;
    datum.keys = xmalloc(n_cfm_fault * sizeof *datum.keys);
    datum.values = NULL;
    for (i = 0; i < n_cfm_fault; i++) {
        datum.keys[i].boolean = cfm_fault[i];
    }
    ovsdb_datum_sort_unique(&datum, OVSDB_TYPE_BOOLEAN, OVSDB_TYPE_VOID);
    ovsdb_idl_txn_write(&row->header_, &ovsrec_interface_columns[OVSREC_INTERFACE_COL_CFM_FAULT], &datum);
}

void
ovsrec_interface_set_cfm_mpid(const struct ovsrec_interface *row, const int64_t *cfm_mpid, size_t n_cfm_mpid)
{
    struct ovsdb_datum datum;
    size_t i;

    assert(inited);
    datum.n = n_cfm_mpid;
    datum.keys = xmalloc(n_cfm_mpid * sizeof *datum.keys);
    datum.values = NULL;
    for (i = 0; i < n_cfm_mpid; i++) {
        datum.keys[i].integer = cfm_mpid[i];
    }
    ovsdb_datum_sort_unique(&datum, OVSDB_TYPE_INTEGER, OVSDB_TYPE_VOID);
    ovsdb_idl_txn_write(&row->header_, &ovsrec_interface_columns[OVSREC_INTERFACE_COL_CFM_MPID], &datum);
}

void
ovsrec_interface_set_cfm_remote_mpid(const struct ovsrec_interface *row, const int64_t *cfm_remote_mpid, size_t n_cfm_remote_mpid)
{
    struct ovsdb_datum datum;
    size_t i;

    assert(inited);
    datum.n = n_cfm_remote_mpid;
    datum.keys = xmalloc(n_cfm_remote_mpid * sizeof *datum.keys);
    datum.values = NULL;
    for (i = 0; i < n_cfm_remote_mpid; i++) {
        datum.keys[i].integer = cfm_remote_mpid[i];
    }
    ovsdb_datum_sort_unique(&datum, OVSDB_TYPE_INTEGER, OVSDB_TYPE_VOID);
    ovsdb_idl_txn_write(&row->header_, &ovsrec_interface_columns[OVSREC_INTERFACE_COL_CFM_REMOTE_MPID], &datum);
}

void
ovsrec_interface_set_duplex(const struct ovsrec_interface *row, const char *duplex)
{
    struct ovsdb_datum datum;

    assert(inited);
    if (duplex) {
        datum.n = 1;
        datum.keys = xmalloc(sizeof *datum.keys);
        datum.keys[0].string = xstrdup(duplex);
    } else {
        datum.n = 0;
        datum.keys = NULL;
    }
    datum.values = NULL;
    ovsdb_idl_txn_write(&row->header_, &ovsrec_interface_columns[OVSREC_INTERFACE_COL_DUPLEX], &datum);
}

void
ovsrec_interface_set_external_ids(const struct ovsrec_interface *row, char **key_external_ids, char **value_external_ids, size_t n_external_ids)
{
    struct ovsdb_datum datum;
    size_t i;

    assert(inited);
    datum.n = n_external_ids;
    datum.keys = xmalloc(n_external_ids * sizeof *datum.keys);
    datum.values = xmalloc(n_external_ids * sizeof *datum.values);
    for (i = 0; i < n_external_ids; i++) {
        datum.keys[i].string = xstrdup(key_external_ids[i]);
        datum.values[i].string = xstrdup(value_external_ids[i]);
    }
    ovsdb_datum_sort_unique(&datum, OVSDB_TYPE_STRING, OVSDB_TYPE_STRING);
    ovsdb_idl_txn_write(&row->header_, &ovsrec_interface_columns[OVSREC_INTERFACE_COL_EXTERNAL_IDS], &datum);
}

void
ovsrec_interface_set_ingress_policing_burst(const struct ovsrec_interface *row, int64_t ingress_policing_burst)
{
    struct ovsdb_datum datum;

    assert(inited);
    datum.n = 1;
    datum.keys = xmalloc(sizeof *datum.keys);
    datum.keys[0].integer = ingress_policing_burst;
    datum.values = NULL;
    ovsdb_idl_txn_write(&row->header_, &ovsrec_interface_columns[OVSREC_INTERFACE_COL_INGRESS_POLICING_BURST], &datum);
}

void
ovsrec_interface_set_ingress_policing_rate(const struct ovsrec_interface *row, int64_t ingress_policing_rate)
{
    struct ovsdb_datum datum;

    assert(inited);
    datum.n = 1;
    datum.keys = xmalloc(sizeof *datum.keys);
    datum.keys[0].integer = ingress_policing_rate;
    datum.values = NULL;
    ovsdb_idl_txn_write(&row->header_, &ovsrec_interface_columns[OVSREC_INTERFACE_COL_INGRESS_POLICING_RATE], &datum);
}

void
ovsrec_interface_set_lacp_current(const struct ovsrec_interface *row, const bool *lacp_current, size_t n_lacp_current)
{
    struct ovsdb_datum datum;
    size_t i;

    assert(inited);
    datum.n = n_lacp_current;
    datum.keys = xmalloc(n_lacp_current * sizeof *datum.keys);
    datum.values = NULL;
    for (i = 0; i < n_lacp_current; i++) {
        datum.keys[i].boolean = lacp_current[i];
    }
    ovsdb_datum_sort_unique(&datum, OVSDB_TYPE_BOOLEAN, OVSDB_TYPE_VOID);
    ovsdb_idl_txn_write(&row->header_, &ovsrec_interface_columns[OVSREC_INTERFACE_COL_LACP_CURRENT], &datum);
}

void
ovsrec_interface_set_link_speed(const struct ovsrec_interface *row, const int64_t *link_speed, size_t n_link_speed)
{
    struct ovsdb_datum datum;
    size_t i;

    assert(inited);
    datum.n = n_link_speed;
    datum.keys = xmalloc(n_link_speed * sizeof *datum.keys);
    datum.values = NULL;
    for (i = 0; i < n_link_speed; i++) {
        datum.keys[i].integer = link_speed[i];
    }
    ovsdb_datum_sort_unique(&datum, OVSDB_TYPE_INTEGER, OVSDB_TYPE_VOID);
    ovsdb_idl_txn_write(&row->header_, &ovsrec_interface_columns[OVSREC_INTERFACE_COL_LINK_SPEED], &datum);
}

void
ovsrec_interface_set_link_state(const struct ovsrec_interface *row, const char *link_state)
{
    struct ovsdb_datum datum;

    assert(inited);
    if (link_state) {
        datum.n = 1;
        datum.keys = xmalloc(sizeof *datum.keys);
        datum.keys[0].string = xstrdup(link_state);
    } else {
        datum.n = 0;
        datum.keys = NULL;
    }
    datum.values = NULL;
    ovsdb_idl_txn_write(&row->header_, &ovsrec_interface_columns[OVSREC_INTERFACE_COL_LINK_STATE], &datum);
}

void
ovsrec_interface_set_mac(const struct ovsrec_interface *row, const char *mac)
{
    struct ovsdb_datum datum;

    assert(inited);
    if (mac) {
        datum.n = 1;
        datum.keys = xmalloc(sizeof *datum.keys);
        datum.keys[0].string = xstrdup(mac);
    } else {
        datum.n = 0;
        datum.keys = NULL;
    }
    datum.values = NULL;
    ovsdb_idl_txn_write(&row->header_, &ovsrec_interface_columns[OVSREC_INTERFACE_COL_MAC], &datum);
}

void
ovsrec_interface_set_mtu(const struct ovsrec_interface *row, const int64_t *mtu, size_t n_mtu)
{
    struct ovsdb_datum datum;
    size_t i;

    assert(inited);
    datum.n = n_mtu;
    datum.keys = xmalloc(n_mtu * sizeof *datum.keys);
    datum.values = NULL;
    for (i = 0; i < n_mtu; i++) {
        datum.keys[i].integer = mtu[i];
    }
    ovsdb_datum_sort_unique(&datum, OVSDB_TYPE_INTEGER, OVSDB_TYPE_VOID);
    ovsdb_idl_txn_write(&row->header_, &ovsrec_interface_columns[OVSREC_INTERFACE_COL_MTU], &datum);
}

void
ovsrec_interface_set_name(const struct ovsrec_interface *row, const char *name)
{
    struct ovsdb_datum datum;

    assert(inited);
    datum.n = 1;
    datum.keys = xmalloc(sizeof *datum.keys);
    datum.keys[0].string = xstrdup(name);
    datum.values = NULL;
    ovsdb_idl_txn_write(&row->header_, &ovsrec_interface_columns[OVSREC_INTERFACE_COL_NAME], &datum);
}

void
ovsrec_interface_set_ofport(const struct ovsrec_interface *row, const int64_t *ofport, size_t n_ofport)
{
    struct ovsdb_datum datum;
    size_t i;

    assert(inited);
    datum.n = n_ofport;
    datum.keys = xmalloc(n_ofport * sizeof *datum.keys);
    datum.values = NULL;
    for (i = 0; i < n_ofport; i++) {
        datum.keys[i].integer = ofport[i];
    }
    ovsdb_datum_sort_unique(&datum, OVSDB_TYPE_INTEGER, OVSDB_TYPE_VOID);
    ovsdb_idl_txn_write(&row->header_, &ovsrec_interface_columns[OVSREC_INTERFACE_COL_OFPORT], &datum);
}

void
ovsrec_interface_set_options(const struct ovsrec_interface *row, char **key_options, char **value_options, size_t n_options)
{
    struct ovsdb_datum datum;
    size_t i;

    assert(inited);
    datum.n = n_options;
    datum.keys = xmalloc(n_options * sizeof *datum.keys);
    datum.values = xmalloc(n_options * sizeof *datum.values);
    for (i = 0; i < n_options; i++) {
        datum.keys[i].string = xstrdup(key_options[i]);
        datum.values[i].string = xstrdup(value_options[i]);
    }
    ovsdb_datum_sort_unique(&datum, OVSDB_TYPE_STRING, OVSDB_TYPE_STRING);
    ovsdb_idl_txn_write(&row->header_, &ovsrec_interface_columns[OVSREC_INTERFACE_COL_OPTIONS], &datum);
}

void
ovsrec_interface_set_other_config(const struct ovsrec_interface *row, char **key_other_config, char **value_other_config, size_t n_other_config)
{
    struct ovsdb_datum datum;
    size_t i;

    assert(inited);
    datum.n = n_other_config;
    datum.keys = xmalloc(n_other_config * sizeof *datum.keys);
    datum.values = xmalloc(n_other_config * sizeof *datum.values);
    for (i = 0; i < n_other_config; i++) {
        datum.keys[i].string = xstrdup(key_other_config[i]);
        datum.values[i].string = xstrdup(value_other_config[i]);
    }
    ovsdb_datum_sort_unique(&datum, OVSDB_TYPE_STRING, OVSDB_TYPE_STRING);
    ovsdb_idl_txn_write(&row->header_, &ovsrec_interface_columns[OVSREC_INTERFACE_COL_OTHER_CONFIG], &datum);
}

void
ovsrec_interface_set_statistics(const struct ovsrec_interface *row, char **key_statistics, const int64_t *value_statistics, size_t n_statistics)
{
    struct ovsdb_datum datum;
    size_t i;

    assert(inited);
    datum.n = n_statistics;
    datum.keys = xmalloc(n_statistics * sizeof *datum.keys);
    datum.values = xmalloc(n_statistics * sizeof *datum.values);
    for (i = 0; i < n_statistics; i++) {
        datum.keys[i].string = xstrdup(key_statistics[i]);
        datum.values[i].integer = value_statistics[i];
    }
    ovsdb_datum_sort_unique(&datum, OVSDB_TYPE_STRING, OVSDB_TYPE_INTEGER);
    ovsdb_idl_txn_write(&row->header_, &ovsrec_interface_columns[OVSREC_INTERFACE_COL_STATISTICS], &datum);
}

void
ovsrec_interface_set_status(const struct ovsrec_interface *row, char **key_status, char **value_status, size_t n_status)
{
    struct ovsdb_datum datum;
    size_t i;

    assert(inited);
    datum.n = n_status;
    datum.keys = xmalloc(n_status * sizeof *datum.keys);
    datum.values = xmalloc(n_status * sizeof *datum.values);
    for (i = 0; i < n_status; i++) {
        datum.keys[i].string = xstrdup(key_status[i]);
        datum.values[i].string = xstrdup(value_status[i]);
    }
    ovsdb_datum_sort_unique(&datum, OVSDB_TYPE_STRING, OVSDB_TYPE_STRING);
    ovsdb_idl_txn_write(&row->header_, &ovsrec_interface_columns[OVSREC_INTERFACE_COL_STATUS], &datum);
}

void
ovsrec_interface_set_type(const struct ovsrec_interface *row, const char *type)
{
    struct ovsdb_datum datum;

    assert(inited);
    datum.n = 1;
    datum.keys = xmalloc(sizeof *datum.keys);
    datum.keys[0].string = xstrdup(type);
    datum.values = NULL;
    ovsdb_idl_txn_write(&row->header_, &ovsrec_interface_columns[OVSREC_INTERFACE_COL_TYPE], &datum);
}

struct ovsdb_idl_column ovsrec_interface_columns[OVSREC_INTERFACE_N_COLUMNS];

static void
ovsrec_interface_columns_init(void)
{
    struct ovsdb_idl_column *c;

    /* Initialize ovsrec_interface_col_admin_state. */
    c = &ovsrec_interface_col_admin_state;
    c->name = "admin_state";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_STRING);
    c->type.key.enum_ = xmalloc(sizeof *c->type.key.enum_);
    c->type.key.enum_->n = 2;
    c->type.key.enum_->keys = xmalloc(2 * sizeof *c->type.key.enum_->keys);
    c->type.key.enum_->keys[0].string = xstrdup("down");
    c->type.key.enum_->keys[1].string = xstrdup("up");
    c->type.key.enum_->values = NULL;
    ovsdb_datum_sort_assert(c->type.key.enum_, OVSDB_TYPE_STRING);
    c->type.key.u.string.minLen = 0;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 0;
    c->type.n_max = 1;
    c->parse = ovsrec_interface_parse_admin_state;
    c->unparse = ovsrec_interface_unparse_admin_state;

    /* Initialize ovsrec_interface_col_cfm_fault. */
    c = &ovsrec_interface_col_cfm_fault;
    c->name = "cfm_fault";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_BOOLEAN);
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 0;
    c->type.n_max = 1;
    c->parse = ovsrec_interface_parse_cfm_fault;
    c->unparse = ovsrec_interface_unparse_cfm_fault;

    /* Initialize ovsrec_interface_col_cfm_mpid. */
    c = &ovsrec_interface_col_cfm_mpid;
    c->name = "cfm_mpid";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_INTEGER);
    c->type.key.u.integer.min = INT64_C(1);
    c->type.key.u.integer.max = INT64_C(8191);
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 0;
    c->type.n_max = 1;
    c->parse = ovsrec_interface_parse_cfm_mpid;
    c->unparse = ovsrec_interface_unparse_cfm_mpid;

    /* Initialize ovsrec_interface_col_cfm_remote_mpid. */
    c = &ovsrec_interface_col_cfm_remote_mpid;
    c->name = "cfm_remote_mpid";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_INTEGER);
    c->type.key.u.integer.min = INT64_C(1);
    c->type.key.u.integer.max = INT64_C(8191);
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 0;
    c->type.n_max = 1;
    c->parse = ovsrec_interface_parse_cfm_remote_mpid;
    c->unparse = ovsrec_interface_unparse_cfm_remote_mpid;

    /* Initialize ovsrec_interface_col_duplex. */
    c = &ovsrec_interface_col_duplex;
    c->name = "duplex";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_STRING);
    c->type.key.enum_ = xmalloc(sizeof *c->type.key.enum_);
    c->type.key.enum_->n = 2;
    c->type.key.enum_->keys = xmalloc(2 * sizeof *c->type.key.enum_->keys);
    c->type.key.enum_->keys[0].string = xstrdup("full");
    c->type.key.enum_->keys[1].string = xstrdup("half");
    c->type.key.enum_->values = NULL;
    ovsdb_datum_sort_assert(c->type.key.enum_, OVSDB_TYPE_STRING);
    c->type.key.u.string.minLen = 0;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 0;
    c->type.n_max = 1;
    c->parse = ovsrec_interface_parse_duplex;
    c->unparse = ovsrec_interface_unparse_duplex;

    /* Initialize ovsrec_interface_col_external_ids. */
    c = &ovsrec_interface_col_external_ids;
    c->name = "external_ids";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_STRING);
    c->type.key.u.string.minLen = 0;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_STRING);
    c->type.value.u.string.minLen = 0;
    c->type.n_min = 0;
    c->type.n_max = UINT_MAX;
    c->parse = ovsrec_interface_parse_external_ids;
    c->unparse = ovsrec_interface_unparse_external_ids;

    /* Initialize ovsrec_interface_col_ingress_policing_burst. */
    c = &ovsrec_interface_col_ingress_policing_burst;
    c->name = "ingress_policing_burst";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_INTEGER);
    c->type.key.u.integer.min = INT64_C(0);
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 1;
    c->type.n_max = 1;
    c->parse = ovsrec_interface_parse_ingress_policing_burst;
    c->unparse = ovsrec_interface_unparse_ingress_policing_burst;

    /* Initialize ovsrec_interface_col_ingress_policing_rate. */
    c = &ovsrec_interface_col_ingress_policing_rate;
    c->name = "ingress_policing_rate";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_INTEGER);
    c->type.key.u.integer.min = INT64_C(0);
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 1;
    c->type.n_max = 1;
    c->parse = ovsrec_interface_parse_ingress_policing_rate;
    c->unparse = ovsrec_interface_unparse_ingress_policing_rate;

    /* Initialize ovsrec_interface_col_lacp_current. */
    c = &ovsrec_interface_col_lacp_current;
    c->name = "lacp_current";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_BOOLEAN);
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 0;
    c->type.n_max = 1;
    c->parse = ovsrec_interface_parse_lacp_current;
    c->unparse = ovsrec_interface_unparse_lacp_current;

    /* Initialize ovsrec_interface_col_link_speed. */
    c = &ovsrec_interface_col_link_speed;
    c->name = "link_speed";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_INTEGER);
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 0;
    c->type.n_max = 1;
    c->parse = ovsrec_interface_parse_link_speed;
    c->unparse = ovsrec_interface_unparse_link_speed;

    /* Initialize ovsrec_interface_col_link_state. */
    c = &ovsrec_interface_col_link_state;
    c->name = "link_state";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_STRING);
    c->type.key.enum_ = xmalloc(sizeof *c->type.key.enum_);
    c->type.key.enum_->n = 2;
    c->type.key.enum_->keys = xmalloc(2 * sizeof *c->type.key.enum_->keys);
    c->type.key.enum_->keys[0].string = xstrdup("down");
    c->type.key.enum_->keys[1].string = xstrdup("up");
    c->type.key.enum_->values = NULL;
    ovsdb_datum_sort_assert(c->type.key.enum_, OVSDB_TYPE_STRING);
    c->type.key.u.string.minLen = 0;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 0;
    c->type.n_max = 1;
    c->parse = ovsrec_interface_parse_link_state;
    c->unparse = ovsrec_interface_unparse_link_state;

    /* Initialize ovsrec_interface_col_mac. */
    c = &ovsrec_interface_col_mac;
    c->name = "mac";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_STRING);
    c->type.key.u.string.minLen = 0;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 0;
    c->type.n_max = 1;
    c->parse = ovsrec_interface_parse_mac;
    c->unparse = ovsrec_interface_unparse_mac;

    /* Initialize ovsrec_interface_col_mtu. */
    c = &ovsrec_interface_col_mtu;
    c->name = "mtu";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_INTEGER);
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 0;
    c->type.n_max = 1;
    c->parse = ovsrec_interface_parse_mtu;
    c->unparse = ovsrec_interface_unparse_mtu;

    /* Initialize ovsrec_interface_col_name. */
    c = &ovsrec_interface_col_name;
    c->name = "name";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_STRING);
    c->type.key.u.string.minLen = 0;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 1;
    c->type.n_max = 1;
    c->parse = ovsrec_interface_parse_name;
    c->unparse = ovsrec_interface_unparse_name;

    /* Initialize ovsrec_interface_col_ofport. */
    c = &ovsrec_interface_col_ofport;
    c->name = "ofport";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_INTEGER);
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 0;
    c->type.n_max = 1;
    c->parse = ovsrec_interface_parse_ofport;
    c->unparse = ovsrec_interface_unparse_ofport;

    /* Initialize ovsrec_interface_col_options. */
    c = &ovsrec_interface_col_options;
    c->name = "options";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_STRING);
    c->type.key.u.string.minLen = 0;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_STRING);
    c->type.value.u.string.minLen = 0;
    c->type.n_min = 0;
    c->type.n_max = UINT_MAX;
    c->parse = ovsrec_interface_parse_options;
    c->unparse = ovsrec_interface_unparse_options;

    /* Initialize ovsrec_interface_col_other_config. */
    c = &ovsrec_interface_col_other_config;
    c->name = "other_config";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_STRING);
    c->type.key.u.string.minLen = 0;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_STRING);
    c->type.value.u.string.minLen = 0;
    c->type.n_min = 0;
    c->type.n_max = UINT_MAX;
    c->parse = ovsrec_interface_parse_other_config;
    c->unparse = ovsrec_interface_unparse_other_config;

    /* Initialize ovsrec_interface_col_statistics. */
    c = &ovsrec_interface_col_statistics;
    c->name = "statistics";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_STRING);
    c->type.key.u.string.minLen = 0;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_INTEGER);
    c->type.n_min = 0;
    c->type.n_max = UINT_MAX;
    c->parse = ovsrec_interface_parse_statistics;
    c->unparse = ovsrec_interface_unparse_statistics;

    /* Initialize ovsrec_interface_col_status. */
    c = &ovsrec_interface_col_status;
    c->name = "status";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_STRING);
    c->type.key.u.string.minLen = 0;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_STRING);
    c->type.value.u.string.minLen = 0;
    c->type.n_min = 0;
    c->type.n_max = UINT_MAX;
    c->parse = ovsrec_interface_parse_status;
    c->unparse = ovsrec_interface_unparse_status;

    /* Initialize ovsrec_interface_col_type. */
    c = &ovsrec_interface_col_type;
    c->name = "type";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_STRING);
    c->type.key.u.string.minLen = 0;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 1;
    c->type.n_max = 1;
    c->parse = ovsrec_interface_parse_type;
    c->unparse = ovsrec_interface_unparse_type;
}

/* Manager table. */

static void
ovsrec_manager_parse_connection_mode(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_manager *row = ovsrec_manager_cast(row_);

    assert(inited);
    if (datum->n >= 1) {
        row->connection_mode = datum->keys[0].string;
    } else {
        row->connection_mode = NULL;
    }
}

static void
ovsrec_manager_parse_external_ids(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_manager *row = ovsrec_manager_cast(row_);
    size_t i;

    assert(inited);
    row->key_external_ids = NULL;
    row->value_external_ids = NULL;
    row->n_external_ids = 0;
    for (i = 0; i < datum->n; i++) {
        if (!row->n_external_ids) {
            row->key_external_ids = xmalloc(datum->n * sizeof *row->key_external_ids);
            row->value_external_ids = xmalloc(datum->n * sizeof *row->value_external_ids);
        }
        row->key_external_ids[row->n_external_ids] = datum->keys[i].string;
        row->value_external_ids[row->n_external_ids] = datum->values[i].string;
        row->n_external_ids++;
    }
}

static void
ovsrec_manager_parse_inactivity_probe(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_manager *row = ovsrec_manager_cast(row_);
    size_t n = MIN(1, datum->n);
    size_t i;

    assert(inited);
    row->inactivity_probe = NULL;
    row->n_inactivity_probe = 0;
    for (i = 0; i < n; i++) {
        if (!row->n_inactivity_probe) {
            row->inactivity_probe = xmalloc(n * sizeof *row->inactivity_probe);
        }
        row->inactivity_probe[row->n_inactivity_probe] = datum->keys[i].integer;
        row->n_inactivity_probe++;
    }
}

static void
ovsrec_manager_parse_is_connected(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_manager *row = ovsrec_manager_cast(row_);

    assert(inited);
    if (datum->n >= 1) {
        row->is_connected = datum->keys[0].boolean;
    } else {
        row->is_connected = false;
    }
}

static void
ovsrec_manager_parse_max_backoff(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_manager *row = ovsrec_manager_cast(row_);
    size_t n = MIN(1, datum->n);
    size_t i;

    assert(inited);
    row->max_backoff = NULL;
    row->n_max_backoff = 0;
    for (i = 0; i < n; i++) {
        if (!row->n_max_backoff) {
            row->max_backoff = xmalloc(n * sizeof *row->max_backoff);
        }
        row->max_backoff[row->n_max_backoff] = datum->keys[i].integer;
        row->n_max_backoff++;
    }
}

static void
ovsrec_manager_parse_status(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_manager *row = ovsrec_manager_cast(row_);
    size_t i;

    assert(inited);
    row->key_status = NULL;
    row->value_status = NULL;
    row->n_status = 0;
    for (i = 0; i < datum->n; i++) {
        if (!row->n_status) {
            row->key_status = xmalloc(datum->n * sizeof *row->key_status);
            row->value_status = xmalloc(datum->n * sizeof *row->value_status);
        }
        row->key_status[row->n_status] = datum->keys[i].string;
        row->value_status[row->n_status] = datum->values[i].string;
        row->n_status++;
    }
}

static void
ovsrec_manager_parse_target(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_manager *row = ovsrec_manager_cast(row_);

    assert(inited);
    if (datum->n >= 1) {
        row->target = datum->keys[0].string;
    } else {
        row->target = "";
    }
}

static void
ovsrec_manager_unparse_connection_mode(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
ovsrec_manager_unparse_external_ids(struct ovsdb_idl_row *row_)
{
    struct ovsrec_manager *row = ovsrec_manager_cast(row_);

    assert(inited);
    free(row->key_external_ids);
    free(row->value_external_ids);
}

static void
ovsrec_manager_unparse_inactivity_probe(struct ovsdb_idl_row *row_)
{
    struct ovsrec_manager *row = ovsrec_manager_cast(row_);

    assert(inited);
    free(row->inactivity_probe);
}

static void
ovsrec_manager_unparse_is_connected(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
ovsrec_manager_unparse_max_backoff(struct ovsdb_idl_row *row_)
{
    struct ovsrec_manager *row = ovsrec_manager_cast(row_);

    assert(inited);
    free(row->max_backoff);
}

static void
ovsrec_manager_unparse_status(struct ovsdb_idl_row *row_)
{
    struct ovsrec_manager *row = ovsrec_manager_cast(row_);

    assert(inited);
    free(row->key_status);
    free(row->value_status);
}

static void
ovsrec_manager_unparse_target(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

const struct ovsrec_manager *
ovsrec_manager_first(const struct ovsdb_idl *idl)
{
    return ovsrec_manager_cast(ovsdb_idl_first_row(idl, &ovsrec_table_classes[OVSREC_TABLE_MANAGER]));
}

const struct ovsrec_manager *
ovsrec_manager_next(const struct ovsrec_manager *row)
{
    return ovsrec_manager_cast(ovsdb_idl_next_row(&row->header_));
}

void
ovsrec_manager_delete(const struct ovsrec_manager *row)
{
    ovsdb_idl_txn_delete(&row->header_);
}

struct ovsrec_manager *
ovsrec_manager_insert(struct ovsdb_idl_txn *txn)
{
    return ovsrec_manager_cast(ovsdb_idl_txn_insert(txn, &ovsrec_table_classes[OVSREC_TABLE_MANAGER], NULL));
}


void
ovsrec_manager_verify_connection_mode(const struct ovsrec_manager *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_manager_columns[OVSREC_MANAGER_COL_CONNECTION_MODE]);
}

void
ovsrec_manager_verify_external_ids(const struct ovsrec_manager *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_manager_columns[OVSREC_MANAGER_COL_EXTERNAL_IDS]);
}

void
ovsrec_manager_verify_inactivity_probe(const struct ovsrec_manager *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_manager_columns[OVSREC_MANAGER_COL_INACTIVITY_PROBE]);
}

void
ovsrec_manager_verify_is_connected(const struct ovsrec_manager *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_manager_columns[OVSREC_MANAGER_COL_IS_CONNECTED]);
}

void
ovsrec_manager_verify_max_backoff(const struct ovsrec_manager *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_manager_columns[OVSREC_MANAGER_COL_MAX_BACKOFF]);
}

void
ovsrec_manager_verify_status(const struct ovsrec_manager *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_manager_columns[OVSREC_MANAGER_COL_STATUS]);
}

void
ovsrec_manager_verify_target(const struct ovsrec_manager *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_manager_columns[OVSREC_MANAGER_COL_TARGET]);
}

/* Returns the connection_mode column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes connection_mode's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_manager_get_connection_mode(const struct ovsrec_manager *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &ovsrec_manager_col_connection_mode);
}

/* Returns the external_ids column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * 'value_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes external_ids's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_manager_get_external_ids(const struct ovsrec_manager *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED,
	enum ovsdb_atomic_type value_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_STRING);
    assert(value_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &ovsrec_manager_col_external_ids);
}

/* Returns the inactivity_probe column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_INTEGER.
 * (This helps to avoid silent bugs if someone changes inactivity_probe's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_manager_get_inactivity_probe(const struct ovsrec_manager *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_INTEGER);
    return ovsdb_idl_read(&row->header_, &ovsrec_manager_col_inactivity_probe);
}

/* Returns the is_connected column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_BOOLEAN.
 * (This helps to avoid silent bugs if someone changes is_connected's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_manager_get_is_connected(const struct ovsrec_manager *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_BOOLEAN);
    return ovsdb_idl_read(&row->header_, &ovsrec_manager_col_is_connected);
}

/* Returns the max_backoff column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_INTEGER.
 * (This helps to avoid silent bugs if someone changes max_backoff's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_manager_get_max_backoff(const struct ovsrec_manager *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_INTEGER);
    return ovsdb_idl_read(&row->header_, &ovsrec_manager_col_max_backoff);
}

/* Returns the status column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * 'value_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes status's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_manager_get_status(const struct ovsrec_manager *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED,
	enum ovsdb_atomic_type value_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_STRING);
    assert(value_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &ovsrec_manager_col_status);
}

/* Returns the target column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes target's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_manager_get_target(const struct ovsrec_manager *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &ovsrec_manager_col_target);
}

void
ovsrec_manager_set_connection_mode(const struct ovsrec_manager *row, const char *connection_mode)
{
    struct ovsdb_datum datum;

    assert(inited);
    if (connection_mode) {
        datum.n = 1;
        datum.keys = xmalloc(sizeof *datum.keys);
        datum.keys[0].string = xstrdup(connection_mode);
    } else {
        datum.n = 0;
        datum.keys = NULL;
    }
    datum.values = NULL;
    ovsdb_idl_txn_write(&row->header_, &ovsrec_manager_columns[OVSREC_MANAGER_COL_CONNECTION_MODE], &datum);
}

void
ovsrec_manager_set_external_ids(const struct ovsrec_manager *row, char **key_external_ids, char **value_external_ids, size_t n_external_ids)
{
    struct ovsdb_datum datum;
    size_t i;

    assert(inited);
    datum.n = n_external_ids;
    datum.keys = xmalloc(n_external_ids * sizeof *datum.keys);
    datum.values = xmalloc(n_external_ids * sizeof *datum.values);
    for (i = 0; i < n_external_ids; i++) {
        datum.keys[i].string = xstrdup(key_external_ids[i]);
        datum.values[i].string = xstrdup(value_external_ids[i]);
    }
    ovsdb_datum_sort_unique(&datum, OVSDB_TYPE_STRING, OVSDB_TYPE_STRING);
    ovsdb_idl_txn_write(&row->header_, &ovsrec_manager_columns[OVSREC_MANAGER_COL_EXTERNAL_IDS], &datum);
}

void
ovsrec_manager_set_inactivity_probe(const struct ovsrec_manager *row, const int64_t *inactivity_probe, size_t n_inactivity_probe)
{
    struct ovsdb_datum datum;
    size_t i;

    assert(inited);
    datum.n = n_inactivity_probe;
    datum.keys = xmalloc(n_inactivity_probe * sizeof *datum.keys);
    datum.values = NULL;
    for (i = 0; i < n_inactivity_probe; i++) {
        datum.keys[i].integer = inactivity_probe[i];
    }
    ovsdb_datum_sort_unique(&datum, OVSDB_TYPE_INTEGER, OVSDB_TYPE_VOID);
    ovsdb_idl_txn_write(&row->header_, &ovsrec_manager_columns[OVSREC_MANAGER_COL_INACTIVITY_PROBE], &datum);
}

void
ovsrec_manager_set_is_connected(const struct ovsrec_manager *row, bool is_connected)
{
    struct ovsdb_datum datum;

    assert(inited);
    datum.n = 1;
    datum.keys = xmalloc(sizeof *datum.keys);
    datum.keys[0].boolean = is_connected;
    datum.values = NULL;
    ovsdb_idl_txn_write(&row->header_, &ovsrec_manager_columns[OVSREC_MANAGER_COL_IS_CONNECTED], &datum);
}

void
ovsrec_manager_set_max_backoff(const struct ovsrec_manager *row, const int64_t *max_backoff, size_t n_max_backoff)
{
    struct ovsdb_datum datum;
    size_t i;

    assert(inited);
    datum.n = n_max_backoff;
    datum.keys = xmalloc(n_max_backoff * sizeof *datum.keys);
    datum.values = NULL;
    for (i = 0; i < n_max_backoff; i++) {
        datum.keys[i].integer = max_backoff[i];
    }
    ovsdb_datum_sort_unique(&datum, OVSDB_TYPE_INTEGER, OVSDB_TYPE_VOID);
    ovsdb_idl_txn_write(&row->header_, &ovsrec_manager_columns[OVSREC_MANAGER_COL_MAX_BACKOFF], &datum);
}

void
ovsrec_manager_set_status(const struct ovsrec_manager *row, char **key_status, char **value_status, size_t n_status)
{
    struct ovsdb_datum datum;
    size_t i;

    assert(inited);
    datum.n = n_status;
    datum.keys = xmalloc(n_status * sizeof *datum.keys);
    datum.values = xmalloc(n_status * sizeof *datum.values);
    for (i = 0; i < n_status; i++) {
        datum.keys[i].string = xstrdup(key_status[i]);
        datum.values[i].string = xstrdup(value_status[i]);
    }
    ovsdb_datum_sort_unique(&datum, OVSDB_TYPE_STRING, OVSDB_TYPE_STRING);
    ovsdb_idl_txn_write(&row->header_, &ovsrec_manager_columns[OVSREC_MANAGER_COL_STATUS], &datum);
}

void
ovsrec_manager_set_target(const struct ovsrec_manager *row, const char *target)
{
    struct ovsdb_datum datum;

    assert(inited);
    datum.n = 1;
    datum.keys = xmalloc(sizeof *datum.keys);
    datum.keys[0].string = xstrdup(target);
    datum.values = NULL;
    ovsdb_idl_txn_write(&row->header_, &ovsrec_manager_columns[OVSREC_MANAGER_COL_TARGET], &datum);
}

struct ovsdb_idl_column ovsrec_manager_columns[OVSREC_MANAGER_N_COLUMNS];

static void
ovsrec_manager_columns_init(void)
{
    struct ovsdb_idl_column *c;

    /* Initialize ovsrec_manager_col_connection_mode. */
    c = &ovsrec_manager_col_connection_mode;
    c->name = "connection_mode";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_STRING);
    c->type.key.enum_ = xmalloc(sizeof *c->type.key.enum_);
    c->type.key.enum_->n = 2;
    c->type.key.enum_->keys = xmalloc(2 * sizeof *c->type.key.enum_->keys);
    c->type.key.enum_->keys[0].string = xstrdup("in-band");
    c->type.key.enum_->keys[1].string = xstrdup("out-of-band");
    c->type.key.enum_->values = NULL;
    ovsdb_datum_sort_assert(c->type.key.enum_, OVSDB_TYPE_STRING);
    c->type.key.u.string.minLen = 0;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 0;
    c->type.n_max = 1;
    c->parse = ovsrec_manager_parse_connection_mode;
    c->unparse = ovsrec_manager_unparse_connection_mode;

    /* Initialize ovsrec_manager_col_external_ids. */
    c = &ovsrec_manager_col_external_ids;
    c->name = "external_ids";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_STRING);
    c->type.key.u.string.minLen = 0;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_STRING);
    c->type.value.u.string.minLen = 0;
    c->type.n_min = 0;
    c->type.n_max = UINT_MAX;
    c->parse = ovsrec_manager_parse_external_ids;
    c->unparse = ovsrec_manager_unparse_external_ids;

    /* Initialize ovsrec_manager_col_inactivity_probe. */
    c = &ovsrec_manager_col_inactivity_probe;
    c->name = "inactivity_probe";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_INTEGER);
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 0;
    c->type.n_max = 1;
    c->parse = ovsrec_manager_parse_inactivity_probe;
    c->unparse = ovsrec_manager_unparse_inactivity_probe;

    /* Initialize ovsrec_manager_col_is_connected. */
    c = &ovsrec_manager_col_is_connected;
    c->name = "is_connected";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_BOOLEAN);
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 1;
    c->type.n_max = 1;
    c->parse = ovsrec_manager_parse_is_connected;
    c->unparse = ovsrec_manager_unparse_is_connected;

    /* Initialize ovsrec_manager_col_max_backoff. */
    c = &ovsrec_manager_col_max_backoff;
    c->name = "max_backoff";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_INTEGER);
    c->type.key.u.integer.min = INT64_C(1000);
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 0;
    c->type.n_max = 1;
    c->parse = ovsrec_manager_parse_max_backoff;
    c->unparse = ovsrec_manager_unparse_max_backoff;

    /* Initialize ovsrec_manager_col_status. */
    c = &ovsrec_manager_col_status;
    c->name = "status";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_STRING);
    c->type.key.u.string.minLen = 0;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_STRING);
    c->type.value.u.string.minLen = 0;
    c->type.n_min = 0;
    c->type.n_max = UINT_MAX;
    c->parse = ovsrec_manager_parse_status;
    c->unparse = ovsrec_manager_unparse_status;

    /* Initialize ovsrec_manager_col_target. */
    c = &ovsrec_manager_col_target;
    c->name = "target";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_STRING);
    c->type.key.u.string.minLen = 0;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 1;
    c->type.n_max = 1;
    c->parse = ovsrec_manager_parse_target;
    c->unparse = ovsrec_manager_unparse_target;
}

/* Mirror table. */

static void
ovsrec_mirror_parse_external_ids(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_mirror *row = ovsrec_mirror_cast(row_);
    size_t i;

    assert(inited);
    row->key_external_ids = NULL;
    row->value_external_ids = NULL;
    row->n_external_ids = 0;
    for (i = 0; i < datum->n; i++) {
        if (!row->n_external_ids) {
            row->key_external_ids = xmalloc(datum->n * sizeof *row->key_external_ids);
            row->value_external_ids = xmalloc(datum->n * sizeof *row->value_external_ids);
        }
        row->key_external_ids[row->n_external_ids] = datum->keys[i].string;
        row->value_external_ids[row->n_external_ids] = datum->values[i].string;
        row->n_external_ids++;
    }
}

static void
ovsrec_mirror_parse_name(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_mirror *row = ovsrec_mirror_cast(row_);

    assert(inited);
    if (datum->n >= 1) {
        row->name = datum->keys[0].string;
    } else {
        row->name = "";
    }
}

static void
ovsrec_mirror_parse_output_port(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_mirror *row = ovsrec_mirror_cast(row_);

    assert(inited);
    if (datum->n >= 1) {
        row->output_port = ovsrec_port_cast(ovsdb_idl_get_row_arc(row_, &ovsrec_table_classes[OVSREC_TABLE_PORT], &datum->keys[0].uuid));
    } else {
        row->output_port = NULL;
    }
}

static void
ovsrec_mirror_parse_output_vlan(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_mirror *row = ovsrec_mirror_cast(row_);
    size_t n = MIN(1, datum->n);
    size_t i;

    assert(inited);
    row->output_vlan = NULL;
    row->n_output_vlan = 0;
    for (i = 0; i < n; i++) {
        if (!row->n_output_vlan) {
            row->output_vlan = xmalloc(n * sizeof *row->output_vlan);
        }
        row->output_vlan[row->n_output_vlan] = datum->keys[i].integer;
        row->n_output_vlan++;
    }
}

static void
ovsrec_mirror_parse_select_all(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_mirror *row = ovsrec_mirror_cast(row_);

    assert(inited);
    if (datum->n >= 1) {
        row->select_all = datum->keys[0].boolean;
    } else {
        row->select_all = false;
    }
}

static void
ovsrec_mirror_parse_select_dst_port(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_mirror *row = ovsrec_mirror_cast(row_);
    size_t i;

    assert(inited);
    row->select_dst_port = NULL;
    row->n_select_dst_port = 0;
    for (i = 0; i < datum->n; i++) {
        struct ovsrec_port *keyRow = ovsrec_port_cast(ovsdb_idl_get_row_arc(row_, &ovsrec_table_classes[OVSREC_TABLE_PORT], &datum->keys[i].uuid));
        if (keyRow) {
            if (!row->n_select_dst_port) {
                row->select_dst_port = xmalloc(datum->n * sizeof *row->select_dst_port);
            }
            row->select_dst_port[row->n_select_dst_port] = keyRow;
            row->n_select_dst_port++;
        }
    }
}

static void
ovsrec_mirror_parse_select_src_port(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_mirror *row = ovsrec_mirror_cast(row_);
    size_t i;

    assert(inited);
    row->select_src_port = NULL;
    row->n_select_src_port = 0;
    for (i = 0; i < datum->n; i++) {
        struct ovsrec_port *keyRow = ovsrec_port_cast(ovsdb_idl_get_row_arc(row_, &ovsrec_table_classes[OVSREC_TABLE_PORT], &datum->keys[i].uuid));
        if (keyRow) {
            if (!row->n_select_src_port) {
                row->select_src_port = xmalloc(datum->n * sizeof *row->select_src_port);
            }
            row->select_src_port[row->n_select_src_port] = keyRow;
            row->n_select_src_port++;
        }
    }
}

static void
ovsrec_mirror_parse_select_vlan(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_mirror *row = ovsrec_mirror_cast(row_);
    size_t n = MIN(4096, datum->n);
    size_t i;

    assert(inited);
    row->select_vlan = NULL;
    row->n_select_vlan = 0;
    for (i = 0; i < n; i++) {
        if (!row->n_select_vlan) {
            row->select_vlan = xmalloc(n * sizeof *row->select_vlan);
        }
        row->select_vlan[row->n_select_vlan] = datum->keys[i].integer;
        row->n_select_vlan++;
    }
}

static void
ovsrec_mirror_unparse_external_ids(struct ovsdb_idl_row *row_)
{
    struct ovsrec_mirror *row = ovsrec_mirror_cast(row_);

    assert(inited);
    free(row->key_external_ids);
    free(row->value_external_ids);
}

static void
ovsrec_mirror_unparse_name(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
ovsrec_mirror_unparse_output_port(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
ovsrec_mirror_unparse_output_vlan(struct ovsdb_idl_row *row_)
{
    struct ovsrec_mirror *row = ovsrec_mirror_cast(row_);

    assert(inited);
    free(row->output_vlan);
}

static void
ovsrec_mirror_unparse_select_all(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
ovsrec_mirror_unparse_select_dst_port(struct ovsdb_idl_row *row_)
{
    struct ovsrec_mirror *row = ovsrec_mirror_cast(row_);

    assert(inited);
    free(row->select_dst_port);
}

static void
ovsrec_mirror_unparse_select_src_port(struct ovsdb_idl_row *row_)
{
    struct ovsrec_mirror *row = ovsrec_mirror_cast(row_);

    assert(inited);
    free(row->select_src_port);
}

static void
ovsrec_mirror_unparse_select_vlan(struct ovsdb_idl_row *row_)
{
    struct ovsrec_mirror *row = ovsrec_mirror_cast(row_);

    assert(inited);
    free(row->select_vlan);
}

const struct ovsrec_mirror *
ovsrec_mirror_first(const struct ovsdb_idl *idl)
{
    return ovsrec_mirror_cast(ovsdb_idl_first_row(idl, &ovsrec_table_classes[OVSREC_TABLE_MIRROR]));
}

const struct ovsrec_mirror *
ovsrec_mirror_next(const struct ovsrec_mirror *row)
{
    return ovsrec_mirror_cast(ovsdb_idl_next_row(&row->header_));
}

void
ovsrec_mirror_delete(const struct ovsrec_mirror *row)
{
    ovsdb_idl_txn_delete(&row->header_);
}

struct ovsrec_mirror *
ovsrec_mirror_insert(struct ovsdb_idl_txn *txn)
{
    return ovsrec_mirror_cast(ovsdb_idl_txn_insert(txn, &ovsrec_table_classes[OVSREC_TABLE_MIRROR], NULL));
}


void
ovsrec_mirror_verify_external_ids(const struct ovsrec_mirror *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_mirror_columns[OVSREC_MIRROR_COL_EXTERNAL_IDS]);
}

void
ovsrec_mirror_verify_name(const struct ovsrec_mirror *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_mirror_columns[OVSREC_MIRROR_COL_NAME]);
}

void
ovsrec_mirror_verify_output_port(const struct ovsrec_mirror *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_mirror_columns[OVSREC_MIRROR_COL_OUTPUT_PORT]);
}

void
ovsrec_mirror_verify_output_vlan(const struct ovsrec_mirror *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_mirror_columns[OVSREC_MIRROR_COL_OUTPUT_VLAN]);
}

void
ovsrec_mirror_verify_select_all(const struct ovsrec_mirror *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_mirror_columns[OVSREC_MIRROR_COL_SELECT_ALL]);
}

void
ovsrec_mirror_verify_select_dst_port(const struct ovsrec_mirror *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_mirror_columns[OVSREC_MIRROR_COL_SELECT_DST_PORT]);
}

void
ovsrec_mirror_verify_select_src_port(const struct ovsrec_mirror *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_mirror_columns[OVSREC_MIRROR_COL_SELECT_SRC_PORT]);
}

void
ovsrec_mirror_verify_select_vlan(const struct ovsrec_mirror *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_mirror_columns[OVSREC_MIRROR_COL_SELECT_VLAN]);
}

/* Returns the external_ids column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * 'value_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes external_ids's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_mirror_get_external_ids(const struct ovsrec_mirror *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED,
	enum ovsdb_atomic_type value_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_STRING);
    assert(value_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &ovsrec_mirror_col_external_ids);
}

/* Returns the name column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes name's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_mirror_get_name(const struct ovsrec_mirror *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &ovsrec_mirror_col_name);
}

/* Returns the output_port column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_UUID.
 * (This helps to avoid silent bugs if someone changes output_port's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_mirror_get_output_port(const struct ovsrec_mirror *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_UUID);
    return ovsdb_idl_read(&row->header_, &ovsrec_mirror_col_output_port);
}

/* Returns the output_vlan column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_INTEGER.
 * (This helps to avoid silent bugs if someone changes output_vlan's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_mirror_get_output_vlan(const struct ovsrec_mirror *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_INTEGER);
    return ovsdb_idl_read(&row->header_, &ovsrec_mirror_col_output_vlan);
}

/* Returns the select_all column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_BOOLEAN.
 * (This helps to avoid silent bugs if someone changes select_all's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_mirror_get_select_all(const struct ovsrec_mirror *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_BOOLEAN);
    return ovsdb_idl_read(&row->header_, &ovsrec_mirror_col_select_all);
}

/* Returns the select_dst_port column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_UUID.
 * (This helps to avoid silent bugs if someone changes select_dst_port's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_mirror_get_select_dst_port(const struct ovsrec_mirror *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_UUID);
    return ovsdb_idl_read(&row->header_, &ovsrec_mirror_col_select_dst_port);
}

/* Returns the select_src_port column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_UUID.
 * (This helps to avoid silent bugs if someone changes select_src_port's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_mirror_get_select_src_port(const struct ovsrec_mirror *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_UUID);
    return ovsdb_idl_read(&row->header_, &ovsrec_mirror_col_select_src_port);
}

/* Returns the select_vlan column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_INTEGER.
 * (This helps to avoid silent bugs if someone changes select_vlan's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_mirror_get_select_vlan(const struct ovsrec_mirror *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_INTEGER);
    return ovsdb_idl_read(&row->header_, &ovsrec_mirror_col_select_vlan);
}

void
ovsrec_mirror_set_external_ids(const struct ovsrec_mirror *row, char **key_external_ids, char **value_external_ids, size_t n_external_ids)
{
    struct ovsdb_datum datum;
    size_t i;

    assert(inited);
    datum.n = n_external_ids;
    datum.keys = xmalloc(n_external_ids * sizeof *datum.keys);
    datum.values = xmalloc(n_external_ids * sizeof *datum.values);
    for (i = 0; i < n_external_ids; i++) {
        datum.keys[i].string = xstrdup(key_external_ids[i]);
        datum.values[i].string = xstrdup(value_external_ids[i]);
    }
    ovsdb_datum_sort_unique(&datum, OVSDB_TYPE_STRING, OVSDB_TYPE_STRING);
    ovsdb_idl_txn_write(&row->header_, &ovsrec_mirror_columns[OVSREC_MIRROR_COL_EXTERNAL_IDS], &datum);
}

void
ovsrec_mirror_set_name(const struct ovsrec_mirror *row, const char *name)
{
    struct ovsdb_datum datum;

    assert(inited);
    datum.n = 1;
    datum.keys = xmalloc(sizeof *datum.keys);
    datum.keys[0].string = xstrdup(name);
    datum.values = NULL;
    ovsdb_idl_txn_write(&row->header_, &ovsrec_mirror_columns[OVSREC_MIRROR_COL_NAME], &datum);
}

void
ovsrec_mirror_set_output_port(const struct ovsrec_mirror *row, const struct ovsrec_port *output_port)
{
    struct ovsdb_datum datum;

    assert(inited);
    if (output_port) {
        datum.n = 1;
        datum.keys = xmalloc(sizeof *datum.keys);
        datum.keys[0].uuid = output_port->header_.uuid;
    } else {
        datum.n = 0;
        datum.keys = NULL;
    }
    datum.values = NULL;
    ovsdb_idl_txn_write(&row->header_, &ovsrec_mirror_columns[OVSREC_MIRROR_COL_OUTPUT_PORT], &datum);
}

void
ovsrec_mirror_set_output_vlan(const struct ovsrec_mirror *row, const int64_t *output_vlan, size_t n_output_vlan)
{
    struct ovsdb_datum datum;
    size_t i;

    assert(inited);
    datum.n = n_output_vlan;
    datum.keys = xmalloc(n_output_vlan * sizeof *datum.keys);
    datum.values = NULL;
    for (i = 0; i < n_output_vlan; i++) {
        datum.keys[i].integer = output_vlan[i];
    }
    ovsdb_datum_sort_unique(&datum, OVSDB_TYPE_INTEGER, OVSDB_TYPE_VOID);
    ovsdb_idl_txn_write(&row->header_, &ovsrec_mirror_columns[OVSREC_MIRROR_COL_OUTPUT_VLAN], &datum);
}

void
ovsrec_mirror_set_select_all(const struct ovsrec_mirror *row, bool select_all)
{
    struct ovsdb_datum datum;

    assert(inited);
    datum.n = 1;
    datum.keys = xmalloc(sizeof *datum.keys);
    datum.keys[0].boolean = select_all;
    datum.values = NULL;
    ovsdb_idl_txn_write(&row->header_, &ovsrec_mirror_columns[OVSREC_MIRROR_COL_SELECT_ALL], &datum);
}

void
ovsrec_mirror_set_select_dst_port(const struct ovsrec_mirror *row, struct ovsrec_port **select_dst_port, size_t n_select_dst_port)
{
    struct ovsdb_datum datum;
    size_t i;

    assert(inited);
    datum.n = n_select_dst_port;
    datum.keys = xmalloc(n_select_dst_port * sizeof *datum.keys);
    datum.values = NULL;
    for (i = 0; i < n_select_dst_port; i++) {
        datum.keys[i].uuid = select_dst_port[i]->header_.uuid;
    }
    ovsdb_datum_sort_unique(&datum, OVSDB_TYPE_UUID, OVSDB_TYPE_VOID);
    ovsdb_idl_txn_write(&row->header_, &ovsrec_mirror_columns[OVSREC_MIRROR_COL_SELECT_DST_PORT], &datum);
}

void
ovsrec_mirror_set_select_src_port(const struct ovsrec_mirror *row, struct ovsrec_port **select_src_port, size_t n_select_src_port)
{
    struct ovsdb_datum datum;
    size_t i;

    assert(inited);
    datum.n = n_select_src_port;
    datum.keys = xmalloc(n_select_src_port * sizeof *datum.keys);
    datum.values = NULL;
    for (i = 0; i < n_select_src_port; i++) {
        datum.keys[i].uuid = select_src_port[i]->header_.uuid;
    }
    ovsdb_datum_sort_unique(&datum, OVSDB_TYPE_UUID, OVSDB_TYPE_VOID);
    ovsdb_idl_txn_write(&row->header_, &ovsrec_mirror_columns[OVSREC_MIRROR_COL_SELECT_SRC_PORT], &datum);
}

void
ovsrec_mirror_set_select_vlan(const struct ovsrec_mirror *row, const int64_t *select_vlan, size_t n_select_vlan)
{
    struct ovsdb_datum datum;
    size_t i;

    assert(inited);
    datum.n = n_select_vlan;
    datum.keys = xmalloc(n_select_vlan * sizeof *datum.keys);
    datum.values = NULL;
    for (i = 0; i < n_select_vlan; i++) {
        datum.keys[i].integer = select_vlan[i];
    }
    ovsdb_datum_sort_unique(&datum, OVSDB_TYPE_INTEGER, OVSDB_TYPE_VOID);
    ovsdb_idl_txn_write(&row->header_, &ovsrec_mirror_columns[OVSREC_MIRROR_COL_SELECT_VLAN], &datum);
}

struct ovsdb_idl_column ovsrec_mirror_columns[OVSREC_MIRROR_N_COLUMNS];

static void
ovsrec_mirror_columns_init(void)
{
    struct ovsdb_idl_column *c;

    /* Initialize ovsrec_mirror_col_external_ids. */
    c = &ovsrec_mirror_col_external_ids;
    c->name = "external_ids";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_STRING);
    c->type.key.u.string.minLen = 0;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_STRING);
    c->type.value.u.string.minLen = 0;
    c->type.n_min = 0;
    c->type.n_max = UINT_MAX;
    c->parse = ovsrec_mirror_parse_external_ids;
    c->unparse = ovsrec_mirror_unparse_external_ids;

    /* Initialize ovsrec_mirror_col_name. */
    c = &ovsrec_mirror_col_name;
    c->name = "name";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_STRING);
    c->type.key.u.string.minLen = 0;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 1;
    c->type.n_max = 1;
    c->parse = ovsrec_mirror_parse_name;
    c->unparse = ovsrec_mirror_unparse_name;

    /* Initialize ovsrec_mirror_col_output_port. */
    c = &ovsrec_mirror_col_output_port;
    c->name = "output_port";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_UUID);
    c->type.key.u.uuid.refTableName = "Port";
    c->type.key.u.uuid.refType = OVSDB_REF_WEAK;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 0;
    c->type.n_max = 1;
    c->parse = ovsrec_mirror_parse_output_port;
    c->unparse = ovsrec_mirror_unparse_output_port;

    /* Initialize ovsrec_mirror_col_output_vlan. */
    c = &ovsrec_mirror_col_output_vlan;
    c->name = "output_vlan";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_INTEGER);
    c->type.key.u.integer.min = INT64_C(1);
    c->type.key.u.integer.max = INT64_C(4095);
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 0;
    c->type.n_max = 1;
    c->parse = ovsrec_mirror_parse_output_vlan;
    c->unparse = ovsrec_mirror_unparse_output_vlan;

    /* Initialize ovsrec_mirror_col_select_all. */
    c = &ovsrec_mirror_col_select_all;
    c->name = "select_all";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_BOOLEAN);
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 1;
    c->type.n_max = 1;
    c->parse = ovsrec_mirror_parse_select_all;
    c->unparse = ovsrec_mirror_unparse_select_all;

    /* Initialize ovsrec_mirror_col_select_dst_port. */
    c = &ovsrec_mirror_col_select_dst_port;
    c->name = "select_dst_port";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_UUID);
    c->type.key.u.uuid.refTableName = "Port";
    c->type.key.u.uuid.refType = OVSDB_REF_WEAK;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 0;
    c->type.n_max = UINT_MAX;
    c->parse = ovsrec_mirror_parse_select_dst_port;
    c->unparse = ovsrec_mirror_unparse_select_dst_port;

    /* Initialize ovsrec_mirror_col_select_src_port. */
    c = &ovsrec_mirror_col_select_src_port;
    c->name = "select_src_port";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_UUID);
    c->type.key.u.uuid.refTableName = "Port";
    c->type.key.u.uuid.refType = OVSDB_REF_WEAK;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 0;
    c->type.n_max = UINT_MAX;
    c->parse = ovsrec_mirror_parse_select_src_port;
    c->unparse = ovsrec_mirror_unparse_select_src_port;

    /* Initialize ovsrec_mirror_col_select_vlan. */
    c = &ovsrec_mirror_col_select_vlan;
    c->name = "select_vlan";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_INTEGER);
    c->type.key.u.integer.min = INT64_C(0);
    c->type.key.u.integer.max = INT64_C(4095);
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 0;
    c->type.n_max = 4096;
    c->parse = ovsrec_mirror_parse_select_vlan;
    c->unparse = ovsrec_mirror_unparse_select_vlan;
}

/* NetFlow table. */

static void
ovsrec_netflow_parse_active_timeout(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_netflow *row = ovsrec_netflow_cast(row_);

    assert(inited);
    if (datum->n >= 1) {
        row->active_timeout = datum->keys[0].integer;
    } else {
        row->active_timeout = 0;
    }
}

static void
ovsrec_netflow_parse_add_id_to_interface(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_netflow *row = ovsrec_netflow_cast(row_);

    assert(inited);
    if (datum->n >= 1) {
        row->add_id_to_interface = datum->keys[0].boolean;
    } else {
        row->add_id_to_interface = false;
    }
}

static void
ovsrec_netflow_parse_engine_id(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_netflow *row = ovsrec_netflow_cast(row_);
    size_t n = MIN(1, datum->n);
    size_t i;

    assert(inited);
    row->engine_id = NULL;
    row->n_engine_id = 0;
    for (i = 0; i < n; i++) {
        if (!row->n_engine_id) {
            row->engine_id = xmalloc(n * sizeof *row->engine_id);
        }
        row->engine_id[row->n_engine_id] = datum->keys[i].integer;
        row->n_engine_id++;
    }
}

static void
ovsrec_netflow_parse_engine_type(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_netflow *row = ovsrec_netflow_cast(row_);
    size_t n = MIN(1, datum->n);
    size_t i;

    assert(inited);
    row->engine_type = NULL;
    row->n_engine_type = 0;
    for (i = 0; i < n; i++) {
        if (!row->n_engine_type) {
            row->engine_type = xmalloc(n * sizeof *row->engine_type);
        }
        row->engine_type[row->n_engine_type] = datum->keys[i].integer;
        row->n_engine_type++;
    }
}

static void
ovsrec_netflow_parse_external_ids(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_netflow *row = ovsrec_netflow_cast(row_);
    size_t i;

    assert(inited);
    row->key_external_ids = NULL;
    row->value_external_ids = NULL;
    row->n_external_ids = 0;
    for (i = 0; i < datum->n; i++) {
        if (!row->n_external_ids) {
            row->key_external_ids = xmalloc(datum->n * sizeof *row->key_external_ids);
            row->value_external_ids = xmalloc(datum->n * sizeof *row->value_external_ids);
        }
        row->key_external_ids[row->n_external_ids] = datum->keys[i].string;
        row->value_external_ids[row->n_external_ids] = datum->values[i].string;
        row->n_external_ids++;
    }
}

static void
ovsrec_netflow_parse_targets(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_netflow *row = ovsrec_netflow_cast(row_);
    size_t i;

    assert(inited);
    row->targets = NULL;
    row->n_targets = 0;
    for (i = 0; i < datum->n; i++) {
        if (!row->n_targets) {
            row->targets = xmalloc(datum->n * sizeof *row->targets);
        }
        row->targets[row->n_targets] = datum->keys[i].string;
        row->n_targets++;
    }
}

static void
ovsrec_netflow_unparse_active_timeout(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
ovsrec_netflow_unparse_add_id_to_interface(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
ovsrec_netflow_unparse_engine_id(struct ovsdb_idl_row *row_)
{
    struct ovsrec_netflow *row = ovsrec_netflow_cast(row_);

    assert(inited);
    free(row->engine_id);
}

static void
ovsrec_netflow_unparse_engine_type(struct ovsdb_idl_row *row_)
{
    struct ovsrec_netflow *row = ovsrec_netflow_cast(row_);

    assert(inited);
    free(row->engine_type);
}

static void
ovsrec_netflow_unparse_external_ids(struct ovsdb_idl_row *row_)
{
    struct ovsrec_netflow *row = ovsrec_netflow_cast(row_);

    assert(inited);
    free(row->key_external_ids);
    free(row->value_external_ids);
}

static void
ovsrec_netflow_unparse_targets(struct ovsdb_idl_row *row_)
{
    struct ovsrec_netflow *row = ovsrec_netflow_cast(row_);

    assert(inited);
    free(row->targets);
}

const struct ovsrec_netflow *
ovsrec_netflow_first(const struct ovsdb_idl *idl)
{
    return ovsrec_netflow_cast(ovsdb_idl_first_row(idl, &ovsrec_table_classes[OVSREC_TABLE_NETFLOW]));
}

const struct ovsrec_netflow *
ovsrec_netflow_next(const struct ovsrec_netflow *row)
{
    return ovsrec_netflow_cast(ovsdb_idl_next_row(&row->header_));
}

void
ovsrec_netflow_delete(const struct ovsrec_netflow *row)
{
    ovsdb_idl_txn_delete(&row->header_);
}

struct ovsrec_netflow *
ovsrec_netflow_insert(struct ovsdb_idl_txn *txn)
{
    return ovsrec_netflow_cast(ovsdb_idl_txn_insert(txn, &ovsrec_table_classes[OVSREC_TABLE_NETFLOW], NULL));
}


void
ovsrec_netflow_verify_active_timeout(const struct ovsrec_netflow *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_netflow_columns[OVSREC_NETFLOW_COL_ACTIVE_TIMEOUT]);
}

void
ovsrec_netflow_verify_add_id_to_interface(const struct ovsrec_netflow *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_netflow_columns[OVSREC_NETFLOW_COL_ADD_ID_TO_INTERFACE]);
}

void
ovsrec_netflow_verify_engine_id(const struct ovsrec_netflow *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_netflow_columns[OVSREC_NETFLOW_COL_ENGINE_ID]);
}

void
ovsrec_netflow_verify_engine_type(const struct ovsrec_netflow *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_netflow_columns[OVSREC_NETFLOW_COL_ENGINE_TYPE]);
}

void
ovsrec_netflow_verify_external_ids(const struct ovsrec_netflow *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_netflow_columns[OVSREC_NETFLOW_COL_EXTERNAL_IDS]);
}

void
ovsrec_netflow_verify_targets(const struct ovsrec_netflow *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_netflow_columns[OVSREC_NETFLOW_COL_TARGETS]);
}

/* Returns the active_timeout column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_INTEGER.
 * (This helps to avoid silent bugs if someone changes active_timeout's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_netflow_get_active_timeout(const struct ovsrec_netflow *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_INTEGER);
    return ovsdb_idl_read(&row->header_, &ovsrec_netflow_col_active_timeout);
}

/* Returns the add_id_to_interface column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_BOOLEAN.
 * (This helps to avoid silent bugs if someone changes add_id_to_interface's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_netflow_get_add_id_to_interface(const struct ovsrec_netflow *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_BOOLEAN);
    return ovsdb_idl_read(&row->header_, &ovsrec_netflow_col_add_id_to_interface);
}

/* Returns the engine_id column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_INTEGER.
 * (This helps to avoid silent bugs if someone changes engine_id's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_netflow_get_engine_id(const struct ovsrec_netflow *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_INTEGER);
    return ovsdb_idl_read(&row->header_, &ovsrec_netflow_col_engine_id);
}

/* Returns the engine_type column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_INTEGER.
 * (This helps to avoid silent bugs if someone changes engine_type's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_netflow_get_engine_type(const struct ovsrec_netflow *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_INTEGER);
    return ovsdb_idl_read(&row->header_, &ovsrec_netflow_col_engine_type);
}

/* Returns the external_ids column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * 'value_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes external_ids's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_netflow_get_external_ids(const struct ovsrec_netflow *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED,
	enum ovsdb_atomic_type value_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_STRING);
    assert(value_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &ovsrec_netflow_col_external_ids);
}

/* Returns the targets column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes targets's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_netflow_get_targets(const struct ovsrec_netflow *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &ovsrec_netflow_col_targets);
}

void
ovsrec_netflow_set_active_timeout(const struct ovsrec_netflow *row, int64_t active_timeout)
{
    struct ovsdb_datum datum;

    assert(inited);
    datum.n = 1;
    datum.keys = xmalloc(sizeof *datum.keys);
    datum.keys[0].integer = active_timeout;
    datum.values = NULL;
    ovsdb_idl_txn_write(&row->header_, &ovsrec_netflow_columns[OVSREC_NETFLOW_COL_ACTIVE_TIMEOUT], &datum);
}

void
ovsrec_netflow_set_add_id_to_interface(const struct ovsrec_netflow *row, bool add_id_to_interface)
{
    struct ovsdb_datum datum;

    assert(inited);
    datum.n = 1;
    datum.keys = xmalloc(sizeof *datum.keys);
    datum.keys[0].boolean = add_id_to_interface;
    datum.values = NULL;
    ovsdb_idl_txn_write(&row->header_, &ovsrec_netflow_columns[OVSREC_NETFLOW_COL_ADD_ID_TO_INTERFACE], &datum);
}

void
ovsrec_netflow_set_engine_id(const struct ovsrec_netflow *row, const int64_t *engine_id, size_t n_engine_id)
{
    struct ovsdb_datum datum;
    size_t i;

    assert(inited);
    datum.n = n_engine_id;
    datum.keys = xmalloc(n_engine_id * sizeof *datum.keys);
    datum.values = NULL;
    for (i = 0; i < n_engine_id; i++) {
        datum.keys[i].integer = engine_id[i];
    }
    ovsdb_datum_sort_unique(&datum, OVSDB_TYPE_INTEGER, OVSDB_TYPE_VOID);
    ovsdb_idl_txn_write(&row->header_, &ovsrec_netflow_columns[OVSREC_NETFLOW_COL_ENGINE_ID], &datum);
}

void
ovsrec_netflow_set_engine_type(const struct ovsrec_netflow *row, const int64_t *engine_type, size_t n_engine_type)
{
    struct ovsdb_datum datum;
    size_t i;

    assert(inited);
    datum.n = n_engine_type;
    datum.keys = xmalloc(n_engine_type * sizeof *datum.keys);
    datum.values = NULL;
    for (i = 0; i < n_engine_type; i++) {
        datum.keys[i].integer = engine_type[i];
    }
    ovsdb_datum_sort_unique(&datum, OVSDB_TYPE_INTEGER, OVSDB_TYPE_VOID);
    ovsdb_idl_txn_write(&row->header_, &ovsrec_netflow_columns[OVSREC_NETFLOW_COL_ENGINE_TYPE], &datum);
}

void
ovsrec_netflow_set_external_ids(const struct ovsrec_netflow *row, char **key_external_ids, char **value_external_ids, size_t n_external_ids)
{
    struct ovsdb_datum datum;
    size_t i;

    assert(inited);
    datum.n = n_external_ids;
    datum.keys = xmalloc(n_external_ids * sizeof *datum.keys);
    datum.values = xmalloc(n_external_ids * sizeof *datum.values);
    for (i = 0; i < n_external_ids; i++) {
        datum.keys[i].string = xstrdup(key_external_ids[i]);
        datum.values[i].string = xstrdup(value_external_ids[i]);
    }
    ovsdb_datum_sort_unique(&datum, OVSDB_TYPE_STRING, OVSDB_TYPE_STRING);
    ovsdb_idl_txn_write(&row->header_, &ovsrec_netflow_columns[OVSREC_NETFLOW_COL_EXTERNAL_IDS], &datum);
}

void
ovsrec_netflow_set_targets(const struct ovsrec_netflow *row, char **targets, size_t n_targets)
{
    struct ovsdb_datum datum;
    size_t i;

    assert(inited);
    datum.n = n_targets;
    datum.keys = xmalloc(n_targets * sizeof *datum.keys);
    datum.values = NULL;
    for (i = 0; i < n_targets; i++) {
        datum.keys[i].string = xstrdup(targets[i]);
    }
    ovsdb_datum_sort_unique(&datum, OVSDB_TYPE_STRING, OVSDB_TYPE_VOID);
    ovsdb_idl_txn_write(&row->header_, &ovsrec_netflow_columns[OVSREC_NETFLOW_COL_TARGETS], &datum);
}

struct ovsdb_idl_column ovsrec_netflow_columns[OVSREC_NETFLOW_N_COLUMNS];

static void
ovsrec_netflow_columns_init(void)
{
    struct ovsdb_idl_column *c;

    /* Initialize ovsrec_netflow_col_active_timeout. */
    c = &ovsrec_netflow_col_active_timeout;
    c->name = "active_timeout";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_INTEGER);
    c->type.key.u.integer.min = INT64_C(-1);
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 1;
    c->type.n_max = 1;
    c->parse = ovsrec_netflow_parse_active_timeout;
    c->unparse = ovsrec_netflow_unparse_active_timeout;

    /* Initialize ovsrec_netflow_col_add_id_to_interface. */
    c = &ovsrec_netflow_col_add_id_to_interface;
    c->name = "add_id_to_interface";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_BOOLEAN);
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 1;
    c->type.n_max = 1;
    c->parse = ovsrec_netflow_parse_add_id_to_interface;
    c->unparse = ovsrec_netflow_unparse_add_id_to_interface;

    /* Initialize ovsrec_netflow_col_engine_id. */
    c = &ovsrec_netflow_col_engine_id;
    c->name = "engine_id";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_INTEGER);
    c->type.key.u.integer.min = INT64_C(0);
    c->type.key.u.integer.max = INT64_C(255);
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 0;
    c->type.n_max = 1;
    c->parse = ovsrec_netflow_parse_engine_id;
    c->unparse = ovsrec_netflow_unparse_engine_id;

    /* Initialize ovsrec_netflow_col_engine_type. */
    c = &ovsrec_netflow_col_engine_type;
    c->name = "engine_type";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_INTEGER);
    c->type.key.u.integer.min = INT64_C(0);
    c->type.key.u.integer.max = INT64_C(255);
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 0;
    c->type.n_max = 1;
    c->parse = ovsrec_netflow_parse_engine_type;
    c->unparse = ovsrec_netflow_unparse_engine_type;

    /* Initialize ovsrec_netflow_col_external_ids. */
    c = &ovsrec_netflow_col_external_ids;
    c->name = "external_ids";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_STRING);
    c->type.key.u.string.minLen = 0;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_STRING);
    c->type.value.u.string.minLen = 0;
    c->type.n_min = 0;
    c->type.n_max = UINT_MAX;
    c->parse = ovsrec_netflow_parse_external_ids;
    c->unparse = ovsrec_netflow_unparse_external_ids;

    /* Initialize ovsrec_netflow_col_targets. */
    c = &ovsrec_netflow_col_targets;
    c->name = "targets";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_STRING);
    c->type.key.u.string.minLen = 0;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 1;
    c->type.n_max = UINT_MAX;
    c->parse = ovsrec_netflow_parse_targets;
    c->unparse = ovsrec_netflow_unparse_targets;
}

/* Open_vSwitch table. */

static void
ovsrec_open_vswitch_parse_bridges(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_open_vswitch *row = ovsrec_open_vswitch_cast(row_);
    size_t i;

    assert(inited);
    row->bridges = NULL;
    row->n_bridges = 0;
    for (i = 0; i < datum->n; i++) {
        struct ovsrec_bridge *keyRow = ovsrec_bridge_cast(ovsdb_idl_get_row_arc(row_, &ovsrec_table_classes[OVSREC_TABLE_BRIDGE], &datum->keys[i].uuid));
        if (keyRow) {
            if (!row->n_bridges) {
                row->bridges = xmalloc(datum->n * sizeof *row->bridges);
            }
            row->bridges[row->n_bridges] = keyRow;
            row->n_bridges++;
        }
    }
}

static void
ovsrec_open_vswitch_parse_capabilities(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_open_vswitch *row = ovsrec_open_vswitch_cast(row_);
    size_t i;

    assert(inited);
    row->key_capabilities = NULL;
    row->value_capabilities = NULL;
    row->n_capabilities = 0;
    for (i = 0; i < datum->n; i++) {
        struct ovsrec_capability *valueRow = ovsrec_capability_cast(ovsdb_idl_get_row_arc(row_, &ovsrec_table_classes[OVSREC_TABLE_CAPABILITY], &datum->values[i].uuid));
        if (valueRow) {
            if (!row->n_capabilities) {
                row->key_capabilities = xmalloc(datum->n * sizeof *row->key_capabilities);
                row->value_capabilities = xmalloc(datum->n * sizeof *row->value_capabilities);
            }
            row->key_capabilities[row->n_capabilities] = datum->keys[i].string;
            row->value_capabilities[row->n_capabilities] = valueRow;
            row->n_capabilities++;
        }
    }
}

static void
ovsrec_open_vswitch_parse_cur_cfg(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_open_vswitch *row = ovsrec_open_vswitch_cast(row_);

    assert(inited);
    if (datum->n >= 1) {
        row->cur_cfg = datum->keys[0].integer;
    } else {
        row->cur_cfg = 0;
    }
}

static void
ovsrec_open_vswitch_parse_db_version(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_open_vswitch *row = ovsrec_open_vswitch_cast(row_);

    assert(inited);
    if (datum->n >= 1) {
        row->db_version = datum->keys[0].string;
    } else {
        row->db_version = NULL;
    }
}

static void
ovsrec_open_vswitch_parse_external_ids(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_open_vswitch *row = ovsrec_open_vswitch_cast(row_);
    size_t i;

    assert(inited);
    row->key_external_ids = NULL;
    row->value_external_ids = NULL;
    row->n_external_ids = 0;
    for (i = 0; i < datum->n; i++) {
        if (!row->n_external_ids) {
            row->key_external_ids = xmalloc(datum->n * sizeof *row->key_external_ids);
            row->value_external_ids = xmalloc(datum->n * sizeof *row->value_external_ids);
        }
        row->key_external_ids[row->n_external_ids] = datum->keys[i].string;
        row->value_external_ids[row->n_external_ids] = datum->values[i].string;
        row->n_external_ids++;
    }
}

static void
ovsrec_open_vswitch_parse_manager_options(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_open_vswitch *row = ovsrec_open_vswitch_cast(row_);
    size_t i;

    assert(inited);
    row->manager_options = NULL;
    row->n_manager_options = 0;
    for (i = 0; i < datum->n; i++) {
        struct ovsrec_manager *keyRow = ovsrec_manager_cast(ovsdb_idl_get_row_arc(row_, &ovsrec_table_classes[OVSREC_TABLE_MANAGER], &datum->keys[i].uuid));
        if (keyRow) {
            if (!row->n_manager_options) {
                row->manager_options = xmalloc(datum->n * sizeof *row->manager_options);
            }
            row->manager_options[row->n_manager_options] = keyRow;
            row->n_manager_options++;
        }
    }
}

static void
ovsrec_open_vswitch_parse_next_cfg(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_open_vswitch *row = ovsrec_open_vswitch_cast(row_);

    assert(inited);
    if (datum->n >= 1) {
        row->next_cfg = datum->keys[0].integer;
    } else {
        row->next_cfg = 0;
    }
}

static void
ovsrec_open_vswitch_parse_other_config(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_open_vswitch *row = ovsrec_open_vswitch_cast(row_);
    size_t i;

    assert(inited);
    row->key_other_config = NULL;
    row->value_other_config = NULL;
    row->n_other_config = 0;
    for (i = 0; i < datum->n; i++) {
        if (!row->n_other_config) {
            row->key_other_config = xmalloc(datum->n * sizeof *row->key_other_config);
            row->value_other_config = xmalloc(datum->n * sizeof *row->value_other_config);
        }
        row->key_other_config[row->n_other_config] = datum->keys[i].string;
        row->value_other_config[row->n_other_config] = datum->values[i].string;
        row->n_other_config++;
    }
}

static void
ovsrec_open_vswitch_parse_ovs_version(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_open_vswitch *row = ovsrec_open_vswitch_cast(row_);

    assert(inited);
    if (datum->n >= 1) {
        row->ovs_version = datum->keys[0].string;
    } else {
        row->ovs_version = NULL;
    }
}

static void
ovsrec_open_vswitch_parse_ssl(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_open_vswitch *row = ovsrec_open_vswitch_cast(row_);

    assert(inited);
    if (datum->n >= 1) {
        row->ssl = ovsrec_ssl_cast(ovsdb_idl_get_row_arc(row_, &ovsrec_table_classes[OVSREC_TABLE_SSL], &datum->keys[0].uuid));
    } else {
        row->ssl = NULL;
    }
}

static void
ovsrec_open_vswitch_parse_statistics(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_open_vswitch *row = ovsrec_open_vswitch_cast(row_);
    size_t i;

    assert(inited);
    row->key_statistics = NULL;
    row->value_statistics = NULL;
    row->n_statistics = 0;
    for (i = 0; i < datum->n; i++) {
        if (!row->n_statistics) {
            row->key_statistics = xmalloc(datum->n * sizeof *row->key_statistics);
            row->value_statistics = xmalloc(datum->n * sizeof *row->value_statistics);
        }
        row->key_statistics[row->n_statistics] = datum->keys[i].string;
        row->value_statistics[row->n_statistics] = datum->values[i].string;
        row->n_statistics++;
    }
}

static void
ovsrec_open_vswitch_parse_system_type(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_open_vswitch *row = ovsrec_open_vswitch_cast(row_);

    assert(inited);
    if (datum->n >= 1) {
        row->system_type = datum->keys[0].string;
    } else {
        row->system_type = NULL;
    }
}

static void
ovsrec_open_vswitch_parse_system_version(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_open_vswitch *row = ovsrec_open_vswitch_cast(row_);

    assert(inited);
    if (datum->n >= 1) {
        row->system_version = datum->keys[0].string;
    } else {
        row->system_version = NULL;
    }
}

static void
ovsrec_open_vswitch_unparse_bridges(struct ovsdb_idl_row *row_)
{
    struct ovsrec_open_vswitch *row = ovsrec_open_vswitch_cast(row_);

    assert(inited);
    free(row->bridges);
}

static void
ovsrec_open_vswitch_unparse_capabilities(struct ovsdb_idl_row *row_)
{
    struct ovsrec_open_vswitch *row = ovsrec_open_vswitch_cast(row_);

    assert(inited);
    free(row->key_capabilities);
    free(row->value_capabilities);
}

static void
ovsrec_open_vswitch_unparse_cur_cfg(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
ovsrec_open_vswitch_unparse_db_version(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
ovsrec_open_vswitch_unparse_external_ids(struct ovsdb_idl_row *row_)
{
    struct ovsrec_open_vswitch *row = ovsrec_open_vswitch_cast(row_);

    assert(inited);
    free(row->key_external_ids);
    free(row->value_external_ids);
}

static void
ovsrec_open_vswitch_unparse_manager_options(struct ovsdb_idl_row *row_)
{
    struct ovsrec_open_vswitch *row = ovsrec_open_vswitch_cast(row_);

    assert(inited);
    free(row->manager_options);
}

static void
ovsrec_open_vswitch_unparse_next_cfg(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
ovsrec_open_vswitch_unparse_other_config(struct ovsdb_idl_row *row_)
{
    struct ovsrec_open_vswitch *row = ovsrec_open_vswitch_cast(row_);

    assert(inited);
    free(row->key_other_config);
    free(row->value_other_config);
}

static void
ovsrec_open_vswitch_unparse_ovs_version(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
ovsrec_open_vswitch_unparse_ssl(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
ovsrec_open_vswitch_unparse_statistics(struct ovsdb_idl_row *row_)
{
    struct ovsrec_open_vswitch *row = ovsrec_open_vswitch_cast(row_);

    assert(inited);
    free(row->key_statistics);
    free(row->value_statistics);
}

static void
ovsrec_open_vswitch_unparse_system_type(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
ovsrec_open_vswitch_unparse_system_version(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

const struct ovsrec_open_vswitch *
ovsrec_open_vswitch_first(const struct ovsdb_idl *idl)
{
    return ovsrec_open_vswitch_cast(ovsdb_idl_first_row(idl, &ovsrec_table_classes[OVSREC_TABLE_OPEN_VSWITCH]));
}

const struct ovsrec_open_vswitch *
ovsrec_open_vswitch_next(const struct ovsrec_open_vswitch *row)
{
    return ovsrec_open_vswitch_cast(ovsdb_idl_next_row(&row->header_));
}

void
ovsrec_open_vswitch_delete(const struct ovsrec_open_vswitch *row)
{
    ovsdb_idl_txn_delete(&row->header_);
}

struct ovsrec_open_vswitch *
ovsrec_open_vswitch_insert(struct ovsdb_idl_txn *txn)
{
    return ovsrec_open_vswitch_cast(ovsdb_idl_txn_insert(txn, &ovsrec_table_classes[OVSREC_TABLE_OPEN_VSWITCH], NULL));
}


void
ovsrec_open_vswitch_verify_bridges(const struct ovsrec_open_vswitch *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_open_vswitch_columns[OVSREC_OPEN_VSWITCH_COL_BRIDGES]);
}

void
ovsrec_open_vswitch_verify_capabilities(const struct ovsrec_open_vswitch *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_open_vswitch_columns[OVSREC_OPEN_VSWITCH_COL_CAPABILITIES]);
}

void
ovsrec_open_vswitch_verify_cur_cfg(const struct ovsrec_open_vswitch *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_open_vswitch_columns[OVSREC_OPEN_VSWITCH_COL_CUR_CFG]);
}

void
ovsrec_open_vswitch_verify_db_version(const struct ovsrec_open_vswitch *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_open_vswitch_columns[OVSREC_OPEN_VSWITCH_COL_DB_VERSION]);
}

void
ovsrec_open_vswitch_verify_external_ids(const struct ovsrec_open_vswitch *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_open_vswitch_columns[OVSREC_OPEN_VSWITCH_COL_EXTERNAL_IDS]);
}

void
ovsrec_open_vswitch_verify_manager_options(const struct ovsrec_open_vswitch *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_open_vswitch_columns[OVSREC_OPEN_VSWITCH_COL_MANAGER_OPTIONS]);
}

void
ovsrec_open_vswitch_verify_next_cfg(const struct ovsrec_open_vswitch *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_open_vswitch_columns[OVSREC_OPEN_VSWITCH_COL_NEXT_CFG]);
}

void
ovsrec_open_vswitch_verify_other_config(const struct ovsrec_open_vswitch *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_open_vswitch_columns[OVSREC_OPEN_VSWITCH_COL_OTHER_CONFIG]);
}

void
ovsrec_open_vswitch_verify_ovs_version(const struct ovsrec_open_vswitch *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_open_vswitch_columns[OVSREC_OPEN_VSWITCH_COL_OVS_VERSION]);
}

void
ovsrec_open_vswitch_verify_ssl(const struct ovsrec_open_vswitch *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_open_vswitch_columns[OVSREC_OPEN_VSWITCH_COL_SSL]);
}

void
ovsrec_open_vswitch_verify_statistics(const struct ovsrec_open_vswitch *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_open_vswitch_columns[OVSREC_OPEN_VSWITCH_COL_STATISTICS]);
}

void
ovsrec_open_vswitch_verify_system_type(const struct ovsrec_open_vswitch *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_open_vswitch_columns[OVSREC_OPEN_VSWITCH_COL_SYSTEM_TYPE]);
}

void
ovsrec_open_vswitch_verify_system_version(const struct ovsrec_open_vswitch *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_open_vswitch_columns[OVSREC_OPEN_VSWITCH_COL_SYSTEM_VERSION]);
}

/* Returns the bridges column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_UUID.
 * (This helps to avoid silent bugs if someone changes bridges's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_open_vswitch_get_bridges(const struct ovsrec_open_vswitch *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_UUID);
    return ovsdb_idl_read(&row->header_, &ovsrec_open_vswitch_col_bridges);
}

/* Returns the capabilities column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * 'value_type' must be OVSDB_TYPE_UUID.
 * (This helps to avoid silent bugs if someone changes capabilities's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_open_vswitch_get_capabilities(const struct ovsrec_open_vswitch *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED,
	enum ovsdb_atomic_type value_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_STRING);
    assert(value_type == OVSDB_TYPE_UUID);
    return ovsdb_idl_read(&row->header_, &ovsrec_open_vswitch_col_capabilities);
}

/* Returns the cur_cfg column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_INTEGER.
 * (This helps to avoid silent bugs if someone changes cur_cfg's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_open_vswitch_get_cur_cfg(const struct ovsrec_open_vswitch *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_INTEGER);
    return ovsdb_idl_read(&row->header_, &ovsrec_open_vswitch_col_cur_cfg);
}

/* Returns the db_version column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes db_version's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_open_vswitch_get_db_version(const struct ovsrec_open_vswitch *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &ovsrec_open_vswitch_col_db_version);
}

/* Returns the external_ids column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * 'value_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes external_ids's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_open_vswitch_get_external_ids(const struct ovsrec_open_vswitch *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED,
	enum ovsdb_atomic_type value_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_STRING);
    assert(value_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &ovsrec_open_vswitch_col_external_ids);
}

/* Returns the manager_options column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_UUID.
 * (This helps to avoid silent bugs if someone changes manager_options's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_open_vswitch_get_manager_options(const struct ovsrec_open_vswitch *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_UUID);
    return ovsdb_idl_read(&row->header_, &ovsrec_open_vswitch_col_manager_options);
}

/* Returns the next_cfg column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_INTEGER.
 * (This helps to avoid silent bugs if someone changes next_cfg's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_open_vswitch_get_next_cfg(const struct ovsrec_open_vswitch *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_INTEGER);
    return ovsdb_idl_read(&row->header_, &ovsrec_open_vswitch_col_next_cfg);
}

/* Returns the other_config column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * 'value_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes other_config's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_open_vswitch_get_other_config(const struct ovsrec_open_vswitch *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED,
	enum ovsdb_atomic_type value_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_STRING);
    assert(value_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &ovsrec_open_vswitch_col_other_config);
}

/* Returns the ovs_version column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes ovs_version's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_open_vswitch_get_ovs_version(const struct ovsrec_open_vswitch *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &ovsrec_open_vswitch_col_ovs_version);
}

/* Returns the ssl column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_UUID.
 * (This helps to avoid silent bugs if someone changes ssl's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_open_vswitch_get_ssl(const struct ovsrec_open_vswitch *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_UUID);
    return ovsdb_idl_read(&row->header_, &ovsrec_open_vswitch_col_ssl);
}

/* Returns the statistics column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * 'value_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes statistics's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_open_vswitch_get_statistics(const struct ovsrec_open_vswitch *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED,
	enum ovsdb_atomic_type value_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_STRING);
    assert(value_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &ovsrec_open_vswitch_col_statistics);
}

/* Returns the system_type column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes system_type's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_open_vswitch_get_system_type(const struct ovsrec_open_vswitch *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &ovsrec_open_vswitch_col_system_type);
}

/* Returns the system_version column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes system_version's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_open_vswitch_get_system_version(const struct ovsrec_open_vswitch *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &ovsrec_open_vswitch_col_system_version);
}

void
ovsrec_open_vswitch_set_bridges(const struct ovsrec_open_vswitch *row, struct ovsrec_bridge **bridges, size_t n_bridges)
{
    struct ovsdb_datum datum;
    size_t i;

    assert(inited);
    datum.n = n_bridges;
    datum.keys = xmalloc(n_bridges * sizeof *datum.keys);
    datum.values = NULL;
    for (i = 0; i < n_bridges; i++) {
        datum.keys[i].uuid = bridges[i]->header_.uuid;
    }
    ovsdb_datum_sort_unique(&datum, OVSDB_TYPE_UUID, OVSDB_TYPE_VOID);
    ovsdb_idl_txn_write(&row->header_, &ovsrec_open_vswitch_columns[OVSREC_OPEN_VSWITCH_COL_BRIDGES], &datum);
}

void
ovsrec_open_vswitch_set_capabilities(const struct ovsrec_open_vswitch *row, char **key_capabilities, struct ovsrec_capability **value_capabilities, size_t n_capabilities)
{
    struct ovsdb_datum datum;
    size_t i;

    assert(inited);
    datum.n = n_capabilities;
    datum.keys = xmalloc(n_capabilities * sizeof *datum.keys);
    datum.values = xmalloc(n_capabilities * sizeof *datum.values);
    for (i = 0; i < n_capabilities; i++) {
        datum.keys[i].string = xstrdup(key_capabilities[i]);
        datum.values[i].uuid = value_capabilities[i]->header_.uuid;
    }
    ovsdb_datum_sort_unique(&datum, OVSDB_TYPE_STRING, OVSDB_TYPE_UUID);
    ovsdb_idl_txn_write(&row->header_, &ovsrec_open_vswitch_columns[OVSREC_OPEN_VSWITCH_COL_CAPABILITIES], &datum);
}

void
ovsrec_open_vswitch_set_cur_cfg(const struct ovsrec_open_vswitch *row, int64_t cur_cfg)
{
    struct ovsdb_datum datum;

    assert(inited);
    datum.n = 1;
    datum.keys = xmalloc(sizeof *datum.keys);
    datum.keys[0].integer = cur_cfg;
    datum.values = NULL;
    ovsdb_idl_txn_write(&row->header_, &ovsrec_open_vswitch_columns[OVSREC_OPEN_VSWITCH_COL_CUR_CFG], &datum);
}

void
ovsrec_open_vswitch_set_db_version(const struct ovsrec_open_vswitch *row, const char *db_version)
{
    struct ovsdb_datum datum;

    assert(inited);
    if (db_version) {
        datum.n = 1;
        datum.keys = xmalloc(sizeof *datum.keys);
        datum.keys[0].string = xstrdup(db_version);
    } else {
        datum.n = 0;
        datum.keys = NULL;
    }
    datum.values = NULL;
    ovsdb_idl_txn_write(&row->header_, &ovsrec_open_vswitch_columns[OVSREC_OPEN_VSWITCH_COL_DB_VERSION], &datum);
}

void
ovsrec_open_vswitch_set_external_ids(const struct ovsrec_open_vswitch *row, char **key_external_ids, char **value_external_ids, size_t n_external_ids)
{
    struct ovsdb_datum datum;
    size_t i;

    assert(inited);
    datum.n = n_external_ids;
    datum.keys = xmalloc(n_external_ids * sizeof *datum.keys);
    datum.values = xmalloc(n_external_ids * sizeof *datum.values);
    for (i = 0; i < n_external_ids; i++) {
        datum.keys[i].string = xstrdup(key_external_ids[i]);
        datum.values[i].string = xstrdup(value_external_ids[i]);
    }
    ovsdb_datum_sort_unique(&datum, OVSDB_TYPE_STRING, OVSDB_TYPE_STRING);
    ovsdb_idl_txn_write(&row->header_, &ovsrec_open_vswitch_columns[OVSREC_OPEN_VSWITCH_COL_EXTERNAL_IDS], &datum);
}

void
ovsrec_open_vswitch_set_manager_options(const struct ovsrec_open_vswitch *row, struct ovsrec_manager **manager_options, size_t n_manager_options)
{
    struct ovsdb_datum datum;
    size_t i;

    assert(inited);
    datum.n = n_manager_options;
    datum.keys = xmalloc(n_manager_options * sizeof *datum.keys);
    datum.values = NULL;
    for (i = 0; i < n_manager_options; i++) {
        datum.keys[i].uuid = manager_options[i]->header_.uuid;
    }
    ovsdb_datum_sort_unique(&datum, OVSDB_TYPE_UUID, OVSDB_TYPE_VOID);
    ovsdb_idl_txn_write(&row->header_, &ovsrec_open_vswitch_columns[OVSREC_OPEN_VSWITCH_COL_MANAGER_OPTIONS], &datum);
}

void
ovsrec_open_vswitch_set_next_cfg(const struct ovsrec_open_vswitch *row, int64_t next_cfg)
{
    struct ovsdb_datum datum;

    assert(inited);
    datum.n = 1;
    datum.keys = xmalloc(sizeof *datum.keys);
    datum.keys[0].integer = next_cfg;
    datum.values = NULL;
    ovsdb_idl_txn_write(&row->header_, &ovsrec_open_vswitch_columns[OVSREC_OPEN_VSWITCH_COL_NEXT_CFG], &datum);
}

void
ovsrec_open_vswitch_set_other_config(const struct ovsrec_open_vswitch *row, char **key_other_config, char **value_other_config, size_t n_other_config)
{
    struct ovsdb_datum datum;
    size_t i;

    assert(inited);
    datum.n = n_other_config;
    datum.keys = xmalloc(n_other_config * sizeof *datum.keys);
    datum.values = xmalloc(n_other_config * sizeof *datum.values);
    for (i = 0; i < n_other_config; i++) {
        datum.keys[i].string = xstrdup(key_other_config[i]);
        datum.values[i].string = xstrdup(value_other_config[i]);
    }
    ovsdb_datum_sort_unique(&datum, OVSDB_TYPE_STRING, OVSDB_TYPE_STRING);
    ovsdb_idl_txn_write(&row->header_, &ovsrec_open_vswitch_columns[OVSREC_OPEN_VSWITCH_COL_OTHER_CONFIG], &datum);
}

void
ovsrec_open_vswitch_set_ovs_version(const struct ovsrec_open_vswitch *row, const char *ovs_version)
{
    struct ovsdb_datum datum;

    assert(inited);
    if (ovs_version) {
        datum.n = 1;
        datum.keys = xmalloc(sizeof *datum.keys);
        datum.keys[0].string = xstrdup(ovs_version);
    } else {
        datum.n = 0;
        datum.keys = NULL;
    }
    datum.values = NULL;
    ovsdb_idl_txn_write(&row->header_, &ovsrec_open_vswitch_columns[OVSREC_OPEN_VSWITCH_COL_OVS_VERSION], &datum);
}

void
ovsrec_open_vswitch_set_ssl(const struct ovsrec_open_vswitch *row, const struct ovsrec_ssl *ssl)
{
    struct ovsdb_datum datum;

    assert(inited);
    if (ssl) {
        datum.n = 1;
        datum.keys = xmalloc(sizeof *datum.keys);
        datum.keys[0].uuid = ssl->header_.uuid;
    } else {
        datum.n = 0;
        datum.keys = NULL;
    }
    datum.values = NULL;
    ovsdb_idl_txn_write(&row->header_, &ovsrec_open_vswitch_columns[OVSREC_OPEN_VSWITCH_COL_SSL], &datum);
}

void
ovsrec_open_vswitch_set_statistics(const struct ovsrec_open_vswitch *row, char **key_statistics, char **value_statistics, size_t n_statistics)
{
    struct ovsdb_datum datum;
    size_t i;

    assert(inited);
    datum.n = n_statistics;
    datum.keys = xmalloc(n_statistics * sizeof *datum.keys);
    datum.values = xmalloc(n_statistics * sizeof *datum.values);
    for (i = 0; i < n_statistics; i++) {
        datum.keys[i].string = xstrdup(key_statistics[i]);
        datum.values[i].string = xstrdup(value_statistics[i]);
    }
    ovsdb_datum_sort_unique(&datum, OVSDB_TYPE_STRING, OVSDB_TYPE_STRING);
    ovsdb_idl_txn_write(&row->header_, &ovsrec_open_vswitch_columns[OVSREC_OPEN_VSWITCH_COL_STATISTICS], &datum);
}

void
ovsrec_open_vswitch_set_system_type(const struct ovsrec_open_vswitch *row, const char *system_type)
{
    struct ovsdb_datum datum;

    assert(inited);
    if (system_type) {
        datum.n = 1;
        datum.keys = xmalloc(sizeof *datum.keys);
        datum.keys[0].string = xstrdup(system_type);
    } else {
        datum.n = 0;
        datum.keys = NULL;
    }
    datum.values = NULL;
    ovsdb_idl_txn_write(&row->header_, &ovsrec_open_vswitch_columns[OVSREC_OPEN_VSWITCH_COL_SYSTEM_TYPE], &datum);
}

void
ovsrec_open_vswitch_set_system_version(const struct ovsrec_open_vswitch *row, const char *system_version)
{
    struct ovsdb_datum datum;

    assert(inited);
    if (system_version) {
        datum.n = 1;
        datum.keys = xmalloc(sizeof *datum.keys);
        datum.keys[0].string = xstrdup(system_version);
    } else {
        datum.n = 0;
        datum.keys = NULL;
    }
    datum.values = NULL;
    ovsdb_idl_txn_write(&row->header_, &ovsrec_open_vswitch_columns[OVSREC_OPEN_VSWITCH_COL_SYSTEM_VERSION], &datum);
}

struct ovsdb_idl_column ovsrec_open_vswitch_columns[OVSREC_OPEN_VSWITCH_N_COLUMNS];

static void
ovsrec_open_vswitch_columns_init(void)
{
    struct ovsdb_idl_column *c;

    /* Initialize ovsrec_open_vswitch_col_bridges. */
    c = &ovsrec_open_vswitch_col_bridges;
    c->name = "bridges";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_UUID);
    c->type.key.u.uuid.refTableName = "Bridge";
    c->type.key.u.uuid.refType = OVSDB_REF_STRONG;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 0;
    c->type.n_max = UINT_MAX;
    c->parse = ovsrec_open_vswitch_parse_bridges;
    c->unparse = ovsrec_open_vswitch_unparse_bridges;

    /* Initialize ovsrec_open_vswitch_col_capabilities. */
    c = &ovsrec_open_vswitch_col_capabilities;
    c->name = "capabilities";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_STRING);
    c->type.key.u.string.minLen = 0;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_UUID);
    c->type.value.u.uuid.refTableName = "Capability";
    c->type.value.u.uuid.refType = OVSDB_REF_STRONG;
    c->type.n_min = 0;
    c->type.n_max = UINT_MAX;
    c->parse = ovsrec_open_vswitch_parse_capabilities;
    c->unparse = ovsrec_open_vswitch_unparse_capabilities;

    /* Initialize ovsrec_open_vswitch_col_cur_cfg. */
    c = &ovsrec_open_vswitch_col_cur_cfg;
    c->name = "cur_cfg";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_INTEGER);
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 1;
    c->type.n_max = 1;
    c->parse = ovsrec_open_vswitch_parse_cur_cfg;
    c->unparse = ovsrec_open_vswitch_unparse_cur_cfg;

    /* Initialize ovsrec_open_vswitch_col_db_version. */
    c = &ovsrec_open_vswitch_col_db_version;
    c->name = "db_version";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_STRING);
    c->type.key.u.string.minLen = 0;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 0;
    c->type.n_max = 1;
    c->parse = ovsrec_open_vswitch_parse_db_version;
    c->unparse = ovsrec_open_vswitch_unparse_db_version;

    /* Initialize ovsrec_open_vswitch_col_external_ids. */
    c = &ovsrec_open_vswitch_col_external_ids;
    c->name = "external_ids";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_STRING);
    c->type.key.u.string.minLen = 0;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_STRING);
    c->type.value.u.string.minLen = 0;
    c->type.n_min = 0;
    c->type.n_max = UINT_MAX;
    c->parse = ovsrec_open_vswitch_parse_external_ids;
    c->unparse = ovsrec_open_vswitch_unparse_external_ids;

    /* Initialize ovsrec_open_vswitch_col_manager_options. */
    c = &ovsrec_open_vswitch_col_manager_options;
    c->name = "manager_options";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_UUID);
    c->type.key.u.uuid.refTableName = "Manager";
    c->type.key.u.uuid.refType = OVSDB_REF_STRONG;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 0;
    c->type.n_max = UINT_MAX;
    c->parse = ovsrec_open_vswitch_parse_manager_options;
    c->unparse = ovsrec_open_vswitch_unparse_manager_options;

    /* Initialize ovsrec_open_vswitch_col_next_cfg. */
    c = &ovsrec_open_vswitch_col_next_cfg;
    c->name = "next_cfg";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_INTEGER);
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 1;
    c->type.n_max = 1;
    c->parse = ovsrec_open_vswitch_parse_next_cfg;
    c->unparse = ovsrec_open_vswitch_unparse_next_cfg;

    /* Initialize ovsrec_open_vswitch_col_other_config. */
    c = &ovsrec_open_vswitch_col_other_config;
    c->name = "other_config";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_STRING);
    c->type.key.u.string.minLen = 0;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_STRING);
    c->type.value.u.string.minLen = 0;
    c->type.n_min = 0;
    c->type.n_max = UINT_MAX;
    c->parse = ovsrec_open_vswitch_parse_other_config;
    c->unparse = ovsrec_open_vswitch_unparse_other_config;

    /* Initialize ovsrec_open_vswitch_col_ovs_version. */
    c = &ovsrec_open_vswitch_col_ovs_version;
    c->name = "ovs_version";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_STRING);
    c->type.key.u.string.minLen = 0;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 0;
    c->type.n_max = 1;
    c->parse = ovsrec_open_vswitch_parse_ovs_version;
    c->unparse = ovsrec_open_vswitch_unparse_ovs_version;

    /* Initialize ovsrec_open_vswitch_col_ssl. */
    c = &ovsrec_open_vswitch_col_ssl;
    c->name = "ssl";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_UUID);
    c->type.key.u.uuid.refTableName = "SSL";
    c->type.key.u.uuid.refType = OVSDB_REF_STRONG;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 0;
    c->type.n_max = 1;
    c->parse = ovsrec_open_vswitch_parse_ssl;
    c->unparse = ovsrec_open_vswitch_unparse_ssl;

    /* Initialize ovsrec_open_vswitch_col_statistics. */
    c = &ovsrec_open_vswitch_col_statistics;
    c->name = "statistics";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_STRING);
    c->type.key.u.string.minLen = 0;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_STRING);
    c->type.value.u.string.minLen = 0;
    c->type.n_min = 0;
    c->type.n_max = UINT_MAX;
    c->parse = ovsrec_open_vswitch_parse_statistics;
    c->unparse = ovsrec_open_vswitch_unparse_statistics;

    /* Initialize ovsrec_open_vswitch_col_system_type. */
    c = &ovsrec_open_vswitch_col_system_type;
    c->name = "system_type";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_STRING);
    c->type.key.u.string.minLen = 0;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 0;
    c->type.n_max = 1;
    c->parse = ovsrec_open_vswitch_parse_system_type;
    c->unparse = ovsrec_open_vswitch_unparse_system_type;

    /* Initialize ovsrec_open_vswitch_col_system_version. */
    c = &ovsrec_open_vswitch_col_system_version;
    c->name = "system_version";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_STRING);
    c->type.key.u.string.minLen = 0;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 0;
    c->type.n_max = 1;
    c->parse = ovsrec_open_vswitch_parse_system_version;
    c->unparse = ovsrec_open_vswitch_unparse_system_version;
}

/* Port table. */

static void
ovsrec_port_parse_bond_downdelay(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_port *row = ovsrec_port_cast(row_);

    assert(inited);
    if (datum->n >= 1) {
        row->bond_downdelay = datum->keys[0].integer;
    } else {
        row->bond_downdelay = 0;
    }
}

static void
ovsrec_port_parse_bond_fake_iface(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_port *row = ovsrec_port_cast(row_);

    assert(inited);
    if (datum->n >= 1) {
        row->bond_fake_iface = datum->keys[0].boolean;
    } else {
        row->bond_fake_iface = false;
    }
}

static void
ovsrec_port_parse_bond_mode(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_port *row = ovsrec_port_cast(row_);

    assert(inited);
    if (datum->n >= 1) {
        row->bond_mode = datum->keys[0].string;
    } else {
        row->bond_mode = NULL;
    }
}

static void
ovsrec_port_parse_bond_updelay(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_port *row = ovsrec_port_cast(row_);

    assert(inited);
    if (datum->n >= 1) {
        row->bond_updelay = datum->keys[0].integer;
    } else {
        row->bond_updelay = 0;
    }
}

static void
ovsrec_port_parse_external_ids(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_port *row = ovsrec_port_cast(row_);
    size_t i;

    assert(inited);
    row->key_external_ids = NULL;
    row->value_external_ids = NULL;
    row->n_external_ids = 0;
    for (i = 0; i < datum->n; i++) {
        if (!row->n_external_ids) {
            row->key_external_ids = xmalloc(datum->n * sizeof *row->key_external_ids);
            row->value_external_ids = xmalloc(datum->n * sizeof *row->value_external_ids);
        }
        row->key_external_ids[row->n_external_ids] = datum->keys[i].string;
        row->value_external_ids[row->n_external_ids] = datum->values[i].string;
        row->n_external_ids++;
    }
}

static void
ovsrec_port_parse_fake_bridge(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_port *row = ovsrec_port_cast(row_);

    assert(inited);
    if (datum->n >= 1) {
        row->fake_bridge = datum->keys[0].boolean;
    } else {
        row->fake_bridge = false;
    }
}

static void
ovsrec_port_parse_interfaces(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_port *row = ovsrec_port_cast(row_);
    size_t i;

    assert(inited);
    row->interfaces = NULL;
    row->n_interfaces = 0;
    for (i = 0; i < datum->n; i++) {
        struct ovsrec_interface *keyRow = ovsrec_interface_cast(ovsdb_idl_get_row_arc(row_, &ovsrec_table_classes[OVSREC_TABLE_INTERFACE], &datum->keys[i].uuid));
        if (keyRow) {
            if (!row->n_interfaces) {
                row->interfaces = xmalloc(datum->n * sizeof *row->interfaces);
            }
            row->interfaces[row->n_interfaces] = keyRow;
            row->n_interfaces++;
        }
    }
}

static void
ovsrec_port_parse_lacp(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_port *row = ovsrec_port_cast(row_);

    assert(inited);
    if (datum->n >= 1) {
        row->lacp = datum->keys[0].string;
    } else {
        row->lacp = NULL;
    }
}

static void
ovsrec_port_parse_mac(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_port *row = ovsrec_port_cast(row_);

    assert(inited);
    if (datum->n >= 1) {
        row->mac = datum->keys[0].string;
    } else {
        row->mac = NULL;
    }
}

static void
ovsrec_port_parse_name(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_port *row = ovsrec_port_cast(row_);

    assert(inited);
    if (datum->n >= 1) {
        row->name = datum->keys[0].string;
    } else {
        row->name = "";
    }
}

static void
ovsrec_port_parse_other_config(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_port *row = ovsrec_port_cast(row_);
    size_t i;

    assert(inited);
    row->key_other_config = NULL;
    row->value_other_config = NULL;
    row->n_other_config = 0;
    for (i = 0; i < datum->n; i++) {
        if (!row->n_other_config) {
            row->key_other_config = xmalloc(datum->n * sizeof *row->key_other_config);
            row->value_other_config = xmalloc(datum->n * sizeof *row->value_other_config);
        }
        row->key_other_config[row->n_other_config] = datum->keys[i].string;
        row->value_other_config[row->n_other_config] = datum->values[i].string;
        row->n_other_config++;
    }
}

static void
ovsrec_port_parse_qos(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_port *row = ovsrec_port_cast(row_);

    assert(inited);
    if (datum->n >= 1) {
        row->qos = ovsrec_qos_cast(ovsdb_idl_get_row_arc(row_, &ovsrec_table_classes[OVSREC_TABLE_QOS], &datum->keys[0].uuid));
    } else {
        row->qos = NULL;
    }
}

static void
ovsrec_port_parse_tag(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_port *row = ovsrec_port_cast(row_);
    size_t n = MIN(1, datum->n);
    size_t i;

    assert(inited);
    row->tag = NULL;
    row->n_tag = 0;
    for (i = 0; i < n; i++) {
        if (!row->n_tag) {
            row->tag = xmalloc(n * sizeof *row->tag);
        }
        row->tag[row->n_tag] = datum->keys[i].integer;
        row->n_tag++;
    }
}

static void
ovsrec_port_parse_trunks(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_port *row = ovsrec_port_cast(row_);
    size_t n = MIN(4096, datum->n);
    size_t i;

    assert(inited);
    row->trunks = NULL;
    row->n_trunks = 0;
    for (i = 0; i < n; i++) {
        if (!row->n_trunks) {
            row->trunks = xmalloc(n * sizeof *row->trunks);
        }
        row->trunks[row->n_trunks] = datum->keys[i].integer;
        row->n_trunks++;
    }
}

static void
ovsrec_port_unparse_bond_downdelay(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
ovsrec_port_unparse_bond_fake_iface(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
ovsrec_port_unparse_bond_mode(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
ovsrec_port_unparse_bond_updelay(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
ovsrec_port_unparse_external_ids(struct ovsdb_idl_row *row_)
{
    struct ovsrec_port *row = ovsrec_port_cast(row_);

    assert(inited);
    free(row->key_external_ids);
    free(row->value_external_ids);
}

static void
ovsrec_port_unparse_fake_bridge(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
ovsrec_port_unparse_interfaces(struct ovsdb_idl_row *row_)
{
    struct ovsrec_port *row = ovsrec_port_cast(row_);

    assert(inited);
    free(row->interfaces);
}

static void
ovsrec_port_unparse_lacp(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
ovsrec_port_unparse_mac(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
ovsrec_port_unparse_name(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
ovsrec_port_unparse_other_config(struct ovsdb_idl_row *row_)
{
    struct ovsrec_port *row = ovsrec_port_cast(row_);

    assert(inited);
    free(row->key_other_config);
    free(row->value_other_config);
}

static void
ovsrec_port_unparse_qos(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
ovsrec_port_unparse_tag(struct ovsdb_idl_row *row_)
{
    struct ovsrec_port *row = ovsrec_port_cast(row_);

    assert(inited);
    free(row->tag);
}

static void
ovsrec_port_unparse_trunks(struct ovsdb_idl_row *row_)
{
    struct ovsrec_port *row = ovsrec_port_cast(row_);

    assert(inited);
    free(row->trunks);
}

const struct ovsrec_port *
ovsrec_port_first(const struct ovsdb_idl *idl)
{
    return ovsrec_port_cast(ovsdb_idl_first_row(idl, &ovsrec_table_classes[OVSREC_TABLE_PORT]));
}

const struct ovsrec_port *
ovsrec_port_next(const struct ovsrec_port *row)
{
    return ovsrec_port_cast(ovsdb_idl_next_row(&row->header_));
}

void
ovsrec_port_delete(const struct ovsrec_port *row)
{
    ovsdb_idl_txn_delete(&row->header_);
}

struct ovsrec_port *
ovsrec_port_insert(struct ovsdb_idl_txn *txn)
{
    return ovsrec_port_cast(ovsdb_idl_txn_insert(txn, &ovsrec_table_classes[OVSREC_TABLE_PORT], NULL));
}


void
ovsrec_port_verify_bond_downdelay(const struct ovsrec_port *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_port_columns[OVSREC_PORT_COL_BOND_DOWNDELAY]);
}

void
ovsrec_port_verify_bond_fake_iface(const struct ovsrec_port *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_port_columns[OVSREC_PORT_COL_BOND_FAKE_IFACE]);
}

void
ovsrec_port_verify_bond_mode(const struct ovsrec_port *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_port_columns[OVSREC_PORT_COL_BOND_MODE]);
}

void
ovsrec_port_verify_bond_updelay(const struct ovsrec_port *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_port_columns[OVSREC_PORT_COL_BOND_UPDELAY]);
}

void
ovsrec_port_verify_external_ids(const struct ovsrec_port *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_port_columns[OVSREC_PORT_COL_EXTERNAL_IDS]);
}

void
ovsrec_port_verify_fake_bridge(const struct ovsrec_port *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_port_columns[OVSREC_PORT_COL_FAKE_BRIDGE]);
}

void
ovsrec_port_verify_interfaces(const struct ovsrec_port *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_port_columns[OVSREC_PORT_COL_INTERFACES]);
}

void
ovsrec_port_verify_lacp(const struct ovsrec_port *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_port_columns[OVSREC_PORT_COL_LACP]);
}

void
ovsrec_port_verify_mac(const struct ovsrec_port *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_port_columns[OVSREC_PORT_COL_MAC]);
}

void
ovsrec_port_verify_name(const struct ovsrec_port *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_port_columns[OVSREC_PORT_COL_NAME]);
}

void
ovsrec_port_verify_other_config(const struct ovsrec_port *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_port_columns[OVSREC_PORT_COL_OTHER_CONFIG]);
}

void
ovsrec_port_verify_qos(const struct ovsrec_port *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_port_columns[OVSREC_PORT_COL_QOS]);
}

void
ovsrec_port_verify_tag(const struct ovsrec_port *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_port_columns[OVSREC_PORT_COL_TAG]);
}

void
ovsrec_port_verify_trunks(const struct ovsrec_port *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_port_columns[OVSREC_PORT_COL_TRUNKS]);
}

/* Returns the bond_downdelay column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_INTEGER.
 * (This helps to avoid silent bugs if someone changes bond_downdelay's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_port_get_bond_downdelay(const struct ovsrec_port *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_INTEGER);
    return ovsdb_idl_read(&row->header_, &ovsrec_port_col_bond_downdelay);
}

/* Returns the bond_fake_iface column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_BOOLEAN.
 * (This helps to avoid silent bugs if someone changes bond_fake_iface's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_port_get_bond_fake_iface(const struct ovsrec_port *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_BOOLEAN);
    return ovsdb_idl_read(&row->header_, &ovsrec_port_col_bond_fake_iface);
}

/* Returns the bond_mode column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes bond_mode's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_port_get_bond_mode(const struct ovsrec_port *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &ovsrec_port_col_bond_mode);
}

/* Returns the bond_updelay column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_INTEGER.
 * (This helps to avoid silent bugs if someone changes bond_updelay's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_port_get_bond_updelay(const struct ovsrec_port *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_INTEGER);
    return ovsdb_idl_read(&row->header_, &ovsrec_port_col_bond_updelay);
}

/* Returns the external_ids column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * 'value_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes external_ids's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_port_get_external_ids(const struct ovsrec_port *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED,
	enum ovsdb_atomic_type value_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_STRING);
    assert(value_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &ovsrec_port_col_external_ids);
}

/* Returns the fake_bridge column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_BOOLEAN.
 * (This helps to avoid silent bugs if someone changes fake_bridge's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_port_get_fake_bridge(const struct ovsrec_port *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_BOOLEAN);
    return ovsdb_idl_read(&row->header_, &ovsrec_port_col_fake_bridge);
}

/* Returns the interfaces column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_UUID.
 * (This helps to avoid silent bugs if someone changes interfaces's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_port_get_interfaces(const struct ovsrec_port *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_UUID);
    return ovsdb_idl_read(&row->header_, &ovsrec_port_col_interfaces);
}

/* Returns the lacp column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes lacp's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_port_get_lacp(const struct ovsrec_port *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &ovsrec_port_col_lacp);
}

/* Returns the mac column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes mac's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_port_get_mac(const struct ovsrec_port *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &ovsrec_port_col_mac);
}

/* Returns the name column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes name's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_port_get_name(const struct ovsrec_port *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &ovsrec_port_col_name);
}

/* Returns the other_config column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * 'value_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes other_config's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_port_get_other_config(const struct ovsrec_port *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED,
	enum ovsdb_atomic_type value_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_STRING);
    assert(value_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &ovsrec_port_col_other_config);
}

/* Returns the qos column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_UUID.
 * (This helps to avoid silent bugs if someone changes qos's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_port_get_qos(const struct ovsrec_port *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_UUID);
    return ovsdb_idl_read(&row->header_, &ovsrec_port_col_qos);
}

/* Returns the tag column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_INTEGER.
 * (This helps to avoid silent bugs if someone changes tag's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_port_get_tag(const struct ovsrec_port *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_INTEGER);
    return ovsdb_idl_read(&row->header_, &ovsrec_port_col_tag);
}

/* Returns the trunks column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_INTEGER.
 * (This helps to avoid silent bugs if someone changes trunks's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_port_get_trunks(const struct ovsrec_port *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_INTEGER);
    return ovsdb_idl_read(&row->header_, &ovsrec_port_col_trunks);
}

void
ovsrec_port_set_bond_downdelay(const struct ovsrec_port *row, int64_t bond_downdelay)
{
    struct ovsdb_datum datum;

    assert(inited);
    datum.n = 1;
    datum.keys = xmalloc(sizeof *datum.keys);
    datum.keys[0].integer = bond_downdelay;
    datum.values = NULL;
    ovsdb_idl_txn_write(&row->header_, &ovsrec_port_columns[OVSREC_PORT_COL_BOND_DOWNDELAY], &datum);
}

void
ovsrec_port_set_bond_fake_iface(const struct ovsrec_port *row, bool bond_fake_iface)
{
    struct ovsdb_datum datum;

    assert(inited);
    datum.n = 1;
    datum.keys = xmalloc(sizeof *datum.keys);
    datum.keys[0].boolean = bond_fake_iface;
    datum.values = NULL;
    ovsdb_idl_txn_write(&row->header_, &ovsrec_port_columns[OVSREC_PORT_COL_BOND_FAKE_IFACE], &datum);
}

void
ovsrec_port_set_bond_mode(const struct ovsrec_port *row, const char *bond_mode)
{
    struct ovsdb_datum datum;

    assert(inited);
    if (bond_mode) {
        datum.n = 1;
        datum.keys = xmalloc(sizeof *datum.keys);
        datum.keys[0].string = xstrdup(bond_mode);
    } else {
        datum.n = 0;
        datum.keys = NULL;
    }
    datum.values = NULL;
    ovsdb_idl_txn_write(&row->header_, &ovsrec_port_columns[OVSREC_PORT_COL_BOND_MODE], &datum);
}

void
ovsrec_port_set_bond_updelay(const struct ovsrec_port *row, int64_t bond_updelay)
{
    struct ovsdb_datum datum;

    assert(inited);
    datum.n = 1;
    datum.keys = xmalloc(sizeof *datum.keys);
    datum.keys[0].integer = bond_updelay;
    datum.values = NULL;
    ovsdb_idl_txn_write(&row->header_, &ovsrec_port_columns[OVSREC_PORT_COL_BOND_UPDELAY], &datum);
}

void
ovsrec_port_set_external_ids(const struct ovsrec_port *row, char **key_external_ids, char **value_external_ids, size_t n_external_ids)
{
    struct ovsdb_datum datum;
    size_t i;

    assert(inited);
    datum.n = n_external_ids;
    datum.keys = xmalloc(n_external_ids * sizeof *datum.keys);
    datum.values = xmalloc(n_external_ids * sizeof *datum.values);
    for (i = 0; i < n_external_ids; i++) {
        datum.keys[i].string = xstrdup(key_external_ids[i]);
        datum.values[i].string = xstrdup(value_external_ids[i]);
    }
    ovsdb_datum_sort_unique(&datum, OVSDB_TYPE_STRING, OVSDB_TYPE_STRING);
    ovsdb_idl_txn_write(&row->header_, &ovsrec_port_columns[OVSREC_PORT_COL_EXTERNAL_IDS], &datum);
}

void
ovsrec_port_set_fake_bridge(const struct ovsrec_port *row, bool fake_bridge)
{
    struct ovsdb_datum datum;

    assert(inited);
    datum.n = 1;
    datum.keys = xmalloc(sizeof *datum.keys);
    datum.keys[0].boolean = fake_bridge;
    datum.values = NULL;
    ovsdb_idl_txn_write(&row->header_, &ovsrec_port_columns[OVSREC_PORT_COL_FAKE_BRIDGE], &datum);
}

void
ovsrec_port_set_interfaces(const struct ovsrec_port *row, struct ovsrec_interface **interfaces, size_t n_interfaces)
{
    struct ovsdb_datum datum;
    size_t i;

    assert(inited);
    datum.n = n_interfaces;
    datum.keys = xmalloc(n_interfaces * sizeof *datum.keys);
    datum.values = NULL;
    for (i = 0; i < n_interfaces; i++) {
        datum.keys[i].uuid = interfaces[i]->header_.uuid;
    }
    ovsdb_datum_sort_unique(&datum, OVSDB_TYPE_UUID, OVSDB_TYPE_VOID);
    ovsdb_idl_txn_write(&row->header_, &ovsrec_port_columns[OVSREC_PORT_COL_INTERFACES], &datum);
}

void
ovsrec_port_set_lacp(const struct ovsrec_port *row, const char *lacp)
{
    struct ovsdb_datum datum;

    assert(inited);
    if (lacp) {
        datum.n = 1;
        datum.keys = xmalloc(sizeof *datum.keys);
        datum.keys[0].string = xstrdup(lacp);
    } else {
        datum.n = 0;
        datum.keys = NULL;
    }
    datum.values = NULL;
    ovsdb_idl_txn_write(&row->header_, &ovsrec_port_columns[OVSREC_PORT_COL_LACP], &datum);
}

void
ovsrec_port_set_mac(const struct ovsrec_port *row, const char *mac)
{
    struct ovsdb_datum datum;

    assert(inited);
    if (mac) {
        datum.n = 1;
        datum.keys = xmalloc(sizeof *datum.keys);
        datum.keys[0].string = xstrdup(mac);
    } else {
        datum.n = 0;
        datum.keys = NULL;
    }
    datum.values = NULL;
    ovsdb_idl_txn_write(&row->header_, &ovsrec_port_columns[OVSREC_PORT_COL_MAC], &datum);
}

void
ovsrec_port_set_name(const struct ovsrec_port *row, const char *name)
{
    struct ovsdb_datum datum;

    assert(inited);
    datum.n = 1;
    datum.keys = xmalloc(sizeof *datum.keys);
    datum.keys[0].string = xstrdup(name);
    datum.values = NULL;
    ovsdb_idl_txn_write(&row->header_, &ovsrec_port_columns[OVSREC_PORT_COL_NAME], &datum);
}

void
ovsrec_port_set_other_config(const struct ovsrec_port *row, char **key_other_config, char **value_other_config, size_t n_other_config)
{
    struct ovsdb_datum datum;
    size_t i;

    assert(inited);
    datum.n = n_other_config;
    datum.keys = xmalloc(n_other_config * sizeof *datum.keys);
    datum.values = xmalloc(n_other_config * sizeof *datum.values);
    for (i = 0; i < n_other_config; i++) {
        datum.keys[i].string = xstrdup(key_other_config[i]);
        datum.values[i].string = xstrdup(value_other_config[i]);
    }
    ovsdb_datum_sort_unique(&datum, OVSDB_TYPE_STRING, OVSDB_TYPE_STRING);
    ovsdb_idl_txn_write(&row->header_, &ovsrec_port_columns[OVSREC_PORT_COL_OTHER_CONFIG], &datum);
}

void
ovsrec_port_set_qos(const struct ovsrec_port *row, const struct ovsrec_qos *qos)
{
    struct ovsdb_datum datum;

    assert(inited);
    if (qos) {
        datum.n = 1;
        datum.keys = xmalloc(sizeof *datum.keys);
        datum.keys[0].uuid = qos->header_.uuid;
    } else {
        datum.n = 0;
        datum.keys = NULL;
    }
    datum.values = NULL;
    ovsdb_idl_txn_write(&row->header_, &ovsrec_port_columns[OVSREC_PORT_COL_QOS], &datum);
}

void
ovsrec_port_set_tag(const struct ovsrec_port *row, const int64_t *tag, size_t n_tag)
{
    struct ovsdb_datum datum;
    size_t i;

    assert(inited);
    datum.n = n_tag;
    datum.keys = xmalloc(n_tag * sizeof *datum.keys);
    datum.values = NULL;
    for (i = 0; i < n_tag; i++) {
        datum.keys[i].integer = tag[i];
    }
    ovsdb_datum_sort_unique(&datum, OVSDB_TYPE_INTEGER, OVSDB_TYPE_VOID);
    ovsdb_idl_txn_write(&row->header_, &ovsrec_port_columns[OVSREC_PORT_COL_TAG], &datum);
}

void
ovsrec_port_set_trunks(const struct ovsrec_port *row, const int64_t *trunks, size_t n_trunks)
{
    struct ovsdb_datum datum;
    size_t i;

    assert(inited);
    datum.n = n_trunks;
    datum.keys = xmalloc(n_trunks * sizeof *datum.keys);
    datum.values = NULL;
    for (i = 0; i < n_trunks; i++) {
        datum.keys[i].integer = trunks[i];
    }
    ovsdb_datum_sort_unique(&datum, OVSDB_TYPE_INTEGER, OVSDB_TYPE_VOID);
    ovsdb_idl_txn_write(&row->header_, &ovsrec_port_columns[OVSREC_PORT_COL_TRUNKS], &datum);
}

struct ovsdb_idl_column ovsrec_port_columns[OVSREC_PORT_N_COLUMNS];

static void
ovsrec_port_columns_init(void)
{
    struct ovsdb_idl_column *c;

    /* Initialize ovsrec_port_col_bond_downdelay. */
    c = &ovsrec_port_col_bond_downdelay;
    c->name = "bond_downdelay";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_INTEGER);
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 1;
    c->type.n_max = 1;
    c->parse = ovsrec_port_parse_bond_downdelay;
    c->unparse = ovsrec_port_unparse_bond_downdelay;

    /* Initialize ovsrec_port_col_bond_fake_iface. */
    c = &ovsrec_port_col_bond_fake_iface;
    c->name = "bond_fake_iface";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_BOOLEAN);
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 1;
    c->type.n_max = 1;
    c->parse = ovsrec_port_parse_bond_fake_iface;
    c->unparse = ovsrec_port_unparse_bond_fake_iface;

    /* Initialize ovsrec_port_col_bond_mode. */
    c = &ovsrec_port_col_bond_mode;
    c->name = "bond_mode";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_STRING);
    c->type.key.enum_ = xmalloc(sizeof *c->type.key.enum_);
    c->type.key.enum_->n = 4;
    c->type.key.enum_->keys = xmalloc(4 * sizeof *c->type.key.enum_->keys);
    c->type.key.enum_->keys[0].string = xstrdup("active-backup");
    c->type.key.enum_->keys[1].string = xstrdup("balance-slb");
    c->type.key.enum_->keys[2].string = xstrdup("balance-tcp");
    c->type.key.enum_->keys[3].string = xstrdup("stable");
    c->type.key.enum_->values = NULL;
    ovsdb_datum_sort_assert(c->type.key.enum_, OVSDB_TYPE_STRING);
    c->type.key.u.string.minLen = 0;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 0;
    c->type.n_max = 1;
    c->parse = ovsrec_port_parse_bond_mode;
    c->unparse = ovsrec_port_unparse_bond_mode;

    /* Initialize ovsrec_port_col_bond_updelay. */
    c = &ovsrec_port_col_bond_updelay;
    c->name = "bond_updelay";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_INTEGER);
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 1;
    c->type.n_max = 1;
    c->parse = ovsrec_port_parse_bond_updelay;
    c->unparse = ovsrec_port_unparse_bond_updelay;

    /* Initialize ovsrec_port_col_external_ids. */
    c = &ovsrec_port_col_external_ids;
    c->name = "external_ids";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_STRING);
    c->type.key.u.string.minLen = 0;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_STRING);
    c->type.value.u.string.minLen = 0;
    c->type.n_min = 0;
    c->type.n_max = UINT_MAX;
    c->parse = ovsrec_port_parse_external_ids;
    c->unparse = ovsrec_port_unparse_external_ids;

    /* Initialize ovsrec_port_col_fake_bridge. */
    c = &ovsrec_port_col_fake_bridge;
    c->name = "fake_bridge";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_BOOLEAN);
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 1;
    c->type.n_max = 1;
    c->parse = ovsrec_port_parse_fake_bridge;
    c->unparse = ovsrec_port_unparse_fake_bridge;

    /* Initialize ovsrec_port_col_interfaces. */
    c = &ovsrec_port_col_interfaces;
    c->name = "interfaces";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_UUID);
    c->type.key.u.uuid.refTableName = "Interface";
    c->type.key.u.uuid.refType = OVSDB_REF_STRONG;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 1;
    c->type.n_max = UINT_MAX;
    c->parse = ovsrec_port_parse_interfaces;
    c->unparse = ovsrec_port_unparse_interfaces;

    /* Initialize ovsrec_port_col_lacp. */
    c = &ovsrec_port_col_lacp;
    c->name = "lacp";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_STRING);
    c->type.key.enum_ = xmalloc(sizeof *c->type.key.enum_);
    c->type.key.enum_->n = 3;
    c->type.key.enum_->keys = xmalloc(3 * sizeof *c->type.key.enum_->keys);
    c->type.key.enum_->keys[0].string = xstrdup("active");
    c->type.key.enum_->keys[1].string = xstrdup("off");
    c->type.key.enum_->keys[2].string = xstrdup("passive");
    c->type.key.enum_->values = NULL;
    ovsdb_datum_sort_assert(c->type.key.enum_, OVSDB_TYPE_STRING);
    c->type.key.u.string.minLen = 0;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 0;
    c->type.n_max = 1;
    c->parse = ovsrec_port_parse_lacp;
    c->unparse = ovsrec_port_unparse_lacp;

    /* Initialize ovsrec_port_col_mac. */
    c = &ovsrec_port_col_mac;
    c->name = "mac";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_STRING);
    c->type.key.u.string.minLen = 0;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 0;
    c->type.n_max = 1;
    c->parse = ovsrec_port_parse_mac;
    c->unparse = ovsrec_port_unparse_mac;

    /* Initialize ovsrec_port_col_name. */
    c = &ovsrec_port_col_name;
    c->name = "name";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_STRING);
    c->type.key.u.string.minLen = 0;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 1;
    c->type.n_max = 1;
    c->parse = ovsrec_port_parse_name;
    c->unparse = ovsrec_port_unparse_name;

    /* Initialize ovsrec_port_col_other_config. */
    c = &ovsrec_port_col_other_config;
    c->name = "other_config";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_STRING);
    c->type.key.u.string.minLen = 0;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_STRING);
    c->type.value.u.string.minLen = 0;
    c->type.n_min = 0;
    c->type.n_max = UINT_MAX;
    c->parse = ovsrec_port_parse_other_config;
    c->unparse = ovsrec_port_unparse_other_config;

    /* Initialize ovsrec_port_col_qos. */
    c = &ovsrec_port_col_qos;
    c->name = "qos";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_UUID);
    c->type.key.u.uuid.refTableName = "QoS";
    c->type.key.u.uuid.refType = OVSDB_REF_STRONG;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 0;
    c->type.n_max = 1;
    c->parse = ovsrec_port_parse_qos;
    c->unparse = ovsrec_port_unparse_qos;

    /* Initialize ovsrec_port_col_tag. */
    c = &ovsrec_port_col_tag;
    c->name = "tag";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_INTEGER);
    c->type.key.u.integer.min = INT64_C(0);
    c->type.key.u.integer.max = INT64_C(4095);
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 0;
    c->type.n_max = 1;
    c->parse = ovsrec_port_parse_tag;
    c->unparse = ovsrec_port_unparse_tag;

    /* Initialize ovsrec_port_col_trunks. */
    c = &ovsrec_port_col_trunks;
    c->name = "trunks";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_INTEGER);
    c->type.key.u.integer.min = INT64_C(0);
    c->type.key.u.integer.max = INT64_C(4095);
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 0;
    c->type.n_max = 4096;
    c->parse = ovsrec_port_parse_trunks;
    c->unparse = ovsrec_port_unparse_trunks;
}

/* QoS table. */

static void
ovsrec_qos_parse_external_ids(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_qos *row = ovsrec_qos_cast(row_);
    size_t i;

    assert(inited);
    row->key_external_ids = NULL;
    row->value_external_ids = NULL;
    row->n_external_ids = 0;
    for (i = 0; i < datum->n; i++) {
        if (!row->n_external_ids) {
            row->key_external_ids = xmalloc(datum->n * sizeof *row->key_external_ids);
            row->value_external_ids = xmalloc(datum->n * sizeof *row->value_external_ids);
        }
        row->key_external_ids[row->n_external_ids] = datum->keys[i].string;
        row->value_external_ids[row->n_external_ids] = datum->values[i].string;
        row->n_external_ids++;
    }
}

static void
ovsrec_qos_parse_other_config(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_qos *row = ovsrec_qos_cast(row_);
    size_t i;

    assert(inited);
    row->key_other_config = NULL;
    row->value_other_config = NULL;
    row->n_other_config = 0;
    for (i = 0; i < datum->n; i++) {
        if (!row->n_other_config) {
            row->key_other_config = xmalloc(datum->n * sizeof *row->key_other_config);
            row->value_other_config = xmalloc(datum->n * sizeof *row->value_other_config);
        }
        row->key_other_config[row->n_other_config] = datum->keys[i].string;
        row->value_other_config[row->n_other_config] = datum->values[i].string;
        row->n_other_config++;
    }
}

static void
ovsrec_qos_parse_queues(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_qos *row = ovsrec_qos_cast(row_);
    size_t i;

    assert(inited);
    row->key_queues = NULL;
    row->value_queues = NULL;
    row->n_queues = 0;
    for (i = 0; i < datum->n; i++) {
        struct ovsrec_queue *valueRow = ovsrec_queue_cast(ovsdb_idl_get_row_arc(row_, &ovsrec_table_classes[OVSREC_TABLE_QUEUE], &datum->values[i].uuid));
        if (valueRow) {
            if (!row->n_queues) {
                row->key_queues = xmalloc(datum->n * sizeof *row->key_queues);
                row->value_queues = xmalloc(datum->n * sizeof *row->value_queues);
            }
            row->key_queues[row->n_queues] = datum->keys[i].integer;
            row->value_queues[row->n_queues] = valueRow;
            row->n_queues++;
        }
    }
}

static void
ovsrec_qos_parse_type(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_qos *row = ovsrec_qos_cast(row_);

    assert(inited);
    if (datum->n >= 1) {
        row->type = datum->keys[0].string;
    } else {
        row->type = "";
    }
}

static void
ovsrec_qos_unparse_external_ids(struct ovsdb_idl_row *row_)
{
    struct ovsrec_qos *row = ovsrec_qos_cast(row_);

    assert(inited);
    free(row->key_external_ids);
    free(row->value_external_ids);
}

static void
ovsrec_qos_unparse_other_config(struct ovsdb_idl_row *row_)
{
    struct ovsrec_qos *row = ovsrec_qos_cast(row_);

    assert(inited);
    free(row->key_other_config);
    free(row->value_other_config);
}

static void
ovsrec_qos_unparse_queues(struct ovsdb_idl_row *row_)
{
    struct ovsrec_qos *row = ovsrec_qos_cast(row_);

    assert(inited);
    free(row->key_queues);
    free(row->value_queues);
}

static void
ovsrec_qos_unparse_type(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

const struct ovsrec_qos *
ovsrec_qos_first(const struct ovsdb_idl *idl)
{
    return ovsrec_qos_cast(ovsdb_idl_first_row(idl, &ovsrec_table_classes[OVSREC_TABLE_QOS]));
}

const struct ovsrec_qos *
ovsrec_qos_next(const struct ovsrec_qos *row)
{
    return ovsrec_qos_cast(ovsdb_idl_next_row(&row->header_));
}

void
ovsrec_qos_delete(const struct ovsrec_qos *row)
{
    ovsdb_idl_txn_delete(&row->header_);
}

struct ovsrec_qos *
ovsrec_qos_insert(struct ovsdb_idl_txn *txn)
{
    return ovsrec_qos_cast(ovsdb_idl_txn_insert(txn, &ovsrec_table_classes[OVSREC_TABLE_QOS], NULL));
}


void
ovsrec_qos_verify_external_ids(const struct ovsrec_qos *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_qos_columns[OVSREC_QOS_COL_EXTERNAL_IDS]);
}

void
ovsrec_qos_verify_other_config(const struct ovsrec_qos *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_qos_columns[OVSREC_QOS_COL_OTHER_CONFIG]);
}

void
ovsrec_qos_verify_queues(const struct ovsrec_qos *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_qos_columns[OVSREC_QOS_COL_QUEUES]);
}

void
ovsrec_qos_verify_type(const struct ovsrec_qos *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_qos_columns[OVSREC_QOS_COL_TYPE]);
}

/* Returns the external_ids column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * 'value_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes external_ids's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_qos_get_external_ids(const struct ovsrec_qos *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED,
	enum ovsdb_atomic_type value_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_STRING);
    assert(value_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &ovsrec_qos_col_external_ids);
}

/* Returns the other_config column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * 'value_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes other_config's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_qos_get_other_config(const struct ovsrec_qos *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED,
	enum ovsdb_atomic_type value_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_STRING);
    assert(value_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &ovsrec_qos_col_other_config);
}

/* Returns the queues column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_INTEGER.
 * 'value_type' must be OVSDB_TYPE_UUID.
 * (This helps to avoid silent bugs if someone changes queues's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_qos_get_queues(const struct ovsrec_qos *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED,
	enum ovsdb_atomic_type value_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_INTEGER);
    assert(value_type == OVSDB_TYPE_UUID);
    return ovsdb_idl_read(&row->header_, &ovsrec_qos_col_queues);
}

/* Returns the type column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes type's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_qos_get_type(const struct ovsrec_qos *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &ovsrec_qos_col_type);
}

void
ovsrec_qos_set_external_ids(const struct ovsrec_qos *row, char **key_external_ids, char **value_external_ids, size_t n_external_ids)
{
    struct ovsdb_datum datum;
    size_t i;

    assert(inited);
    datum.n = n_external_ids;
    datum.keys = xmalloc(n_external_ids * sizeof *datum.keys);
    datum.values = xmalloc(n_external_ids * sizeof *datum.values);
    for (i = 0; i < n_external_ids; i++) {
        datum.keys[i].string = xstrdup(key_external_ids[i]);
        datum.values[i].string = xstrdup(value_external_ids[i]);
    }
    ovsdb_datum_sort_unique(&datum, OVSDB_TYPE_STRING, OVSDB_TYPE_STRING);
    ovsdb_idl_txn_write(&row->header_, &ovsrec_qos_columns[OVSREC_QOS_COL_EXTERNAL_IDS], &datum);
}

void
ovsrec_qos_set_other_config(const struct ovsrec_qos *row, char **key_other_config, char **value_other_config, size_t n_other_config)
{
    struct ovsdb_datum datum;
    size_t i;

    assert(inited);
    datum.n = n_other_config;
    datum.keys = xmalloc(n_other_config * sizeof *datum.keys);
    datum.values = xmalloc(n_other_config * sizeof *datum.values);
    for (i = 0; i < n_other_config; i++) {
        datum.keys[i].string = xstrdup(key_other_config[i]);
        datum.values[i].string = xstrdup(value_other_config[i]);
    }
    ovsdb_datum_sort_unique(&datum, OVSDB_TYPE_STRING, OVSDB_TYPE_STRING);
    ovsdb_idl_txn_write(&row->header_, &ovsrec_qos_columns[OVSREC_QOS_COL_OTHER_CONFIG], &datum);
}

void
ovsrec_qos_set_queues(const struct ovsrec_qos *row, const int64_t *key_queues, struct ovsrec_queue **value_queues, size_t n_queues)
{
    struct ovsdb_datum datum;
    size_t i;

    assert(inited);
    datum.n = n_queues;
    datum.keys = xmalloc(n_queues * sizeof *datum.keys);
    datum.values = xmalloc(n_queues * sizeof *datum.values);
    for (i = 0; i < n_queues; i++) {
        datum.keys[i].integer = key_queues[i];
        datum.values[i].uuid = value_queues[i]->header_.uuid;
    }
    ovsdb_datum_sort_unique(&datum, OVSDB_TYPE_INTEGER, OVSDB_TYPE_UUID);
    ovsdb_idl_txn_write(&row->header_, &ovsrec_qos_columns[OVSREC_QOS_COL_QUEUES], &datum);
}

void
ovsrec_qos_set_type(const struct ovsrec_qos *row, const char *type)
{
    struct ovsdb_datum datum;

    assert(inited);
    datum.n = 1;
    datum.keys = xmalloc(sizeof *datum.keys);
    datum.keys[0].string = xstrdup(type);
    datum.values = NULL;
    ovsdb_idl_txn_write(&row->header_, &ovsrec_qos_columns[OVSREC_QOS_COL_TYPE], &datum);
}

struct ovsdb_idl_column ovsrec_qos_columns[OVSREC_QOS_N_COLUMNS];

static void
ovsrec_qos_columns_init(void)
{
    struct ovsdb_idl_column *c;

    /* Initialize ovsrec_qos_col_external_ids. */
    c = &ovsrec_qos_col_external_ids;
    c->name = "external_ids";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_STRING);
    c->type.key.u.string.minLen = 0;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_STRING);
    c->type.value.u.string.minLen = 0;
    c->type.n_min = 0;
    c->type.n_max = UINT_MAX;
    c->parse = ovsrec_qos_parse_external_ids;
    c->unparse = ovsrec_qos_unparse_external_ids;

    /* Initialize ovsrec_qos_col_other_config. */
    c = &ovsrec_qos_col_other_config;
    c->name = "other_config";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_STRING);
    c->type.key.u.string.minLen = 0;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_STRING);
    c->type.value.u.string.minLen = 0;
    c->type.n_min = 0;
    c->type.n_max = UINT_MAX;
    c->parse = ovsrec_qos_parse_other_config;
    c->unparse = ovsrec_qos_unparse_other_config;

    /* Initialize ovsrec_qos_col_queues. */
    c = &ovsrec_qos_col_queues;
    c->name = "queues";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_INTEGER);
    c->type.key.u.integer.min = INT64_C(0);
    c->type.key.u.integer.max = INT64_C(4294967295);
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_UUID);
    c->type.value.u.uuid.refTableName = "Queue";
    c->type.value.u.uuid.refType = OVSDB_REF_STRONG;
    c->type.n_min = 0;
    c->type.n_max = UINT_MAX;
    c->parse = ovsrec_qos_parse_queues;
    c->unparse = ovsrec_qos_unparse_queues;

    /* Initialize ovsrec_qos_col_type. */
    c = &ovsrec_qos_col_type;
    c->name = "type";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_STRING);
    c->type.key.u.string.minLen = 0;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 1;
    c->type.n_max = 1;
    c->parse = ovsrec_qos_parse_type;
    c->unparse = ovsrec_qos_unparse_type;
}

/* Queue table. */

static void
ovsrec_queue_parse_external_ids(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_queue *row = ovsrec_queue_cast(row_);
    size_t i;

    assert(inited);
    row->key_external_ids = NULL;
    row->value_external_ids = NULL;
    row->n_external_ids = 0;
    for (i = 0; i < datum->n; i++) {
        if (!row->n_external_ids) {
            row->key_external_ids = xmalloc(datum->n * sizeof *row->key_external_ids);
            row->value_external_ids = xmalloc(datum->n * sizeof *row->value_external_ids);
        }
        row->key_external_ids[row->n_external_ids] = datum->keys[i].string;
        row->value_external_ids[row->n_external_ids] = datum->values[i].string;
        row->n_external_ids++;
    }
}

static void
ovsrec_queue_parse_other_config(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_queue *row = ovsrec_queue_cast(row_);
    size_t i;

    assert(inited);
    row->key_other_config = NULL;
    row->value_other_config = NULL;
    row->n_other_config = 0;
    for (i = 0; i < datum->n; i++) {
        if (!row->n_other_config) {
            row->key_other_config = xmalloc(datum->n * sizeof *row->key_other_config);
            row->value_other_config = xmalloc(datum->n * sizeof *row->value_other_config);
        }
        row->key_other_config[row->n_other_config] = datum->keys[i].string;
        row->value_other_config[row->n_other_config] = datum->values[i].string;
        row->n_other_config++;
    }
}

static void
ovsrec_queue_unparse_external_ids(struct ovsdb_idl_row *row_)
{
    struct ovsrec_queue *row = ovsrec_queue_cast(row_);

    assert(inited);
    free(row->key_external_ids);
    free(row->value_external_ids);
}

static void
ovsrec_queue_unparse_other_config(struct ovsdb_idl_row *row_)
{
    struct ovsrec_queue *row = ovsrec_queue_cast(row_);

    assert(inited);
    free(row->key_other_config);
    free(row->value_other_config);
}

const struct ovsrec_queue *
ovsrec_queue_first(const struct ovsdb_idl *idl)
{
    return ovsrec_queue_cast(ovsdb_idl_first_row(idl, &ovsrec_table_classes[OVSREC_TABLE_QUEUE]));
}

const struct ovsrec_queue *
ovsrec_queue_next(const struct ovsrec_queue *row)
{
    return ovsrec_queue_cast(ovsdb_idl_next_row(&row->header_));
}

void
ovsrec_queue_delete(const struct ovsrec_queue *row)
{
    ovsdb_idl_txn_delete(&row->header_);
}

struct ovsrec_queue *
ovsrec_queue_insert(struct ovsdb_idl_txn *txn)
{
    return ovsrec_queue_cast(ovsdb_idl_txn_insert(txn, &ovsrec_table_classes[OVSREC_TABLE_QUEUE], NULL));
}


void
ovsrec_queue_verify_external_ids(const struct ovsrec_queue *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_queue_columns[OVSREC_QUEUE_COL_EXTERNAL_IDS]);
}

void
ovsrec_queue_verify_other_config(const struct ovsrec_queue *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_queue_columns[OVSREC_QUEUE_COL_OTHER_CONFIG]);
}

/* Returns the external_ids column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * 'value_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes external_ids's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_queue_get_external_ids(const struct ovsrec_queue *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED,
	enum ovsdb_atomic_type value_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_STRING);
    assert(value_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &ovsrec_queue_col_external_ids);
}

/* Returns the other_config column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * 'value_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes other_config's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_queue_get_other_config(const struct ovsrec_queue *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED,
	enum ovsdb_atomic_type value_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_STRING);
    assert(value_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &ovsrec_queue_col_other_config);
}

void
ovsrec_queue_set_external_ids(const struct ovsrec_queue *row, char **key_external_ids, char **value_external_ids, size_t n_external_ids)
{
    struct ovsdb_datum datum;
    size_t i;

    assert(inited);
    datum.n = n_external_ids;
    datum.keys = xmalloc(n_external_ids * sizeof *datum.keys);
    datum.values = xmalloc(n_external_ids * sizeof *datum.values);
    for (i = 0; i < n_external_ids; i++) {
        datum.keys[i].string = xstrdup(key_external_ids[i]);
        datum.values[i].string = xstrdup(value_external_ids[i]);
    }
    ovsdb_datum_sort_unique(&datum, OVSDB_TYPE_STRING, OVSDB_TYPE_STRING);
    ovsdb_idl_txn_write(&row->header_, &ovsrec_queue_columns[OVSREC_QUEUE_COL_EXTERNAL_IDS], &datum);
}

void
ovsrec_queue_set_other_config(const struct ovsrec_queue *row, char **key_other_config, char **value_other_config, size_t n_other_config)
{
    struct ovsdb_datum datum;
    size_t i;

    assert(inited);
    datum.n = n_other_config;
    datum.keys = xmalloc(n_other_config * sizeof *datum.keys);
    datum.values = xmalloc(n_other_config * sizeof *datum.values);
    for (i = 0; i < n_other_config; i++) {
        datum.keys[i].string = xstrdup(key_other_config[i]);
        datum.values[i].string = xstrdup(value_other_config[i]);
    }
    ovsdb_datum_sort_unique(&datum, OVSDB_TYPE_STRING, OVSDB_TYPE_STRING);
    ovsdb_idl_txn_write(&row->header_, &ovsrec_queue_columns[OVSREC_QUEUE_COL_OTHER_CONFIG], &datum);
}

struct ovsdb_idl_column ovsrec_queue_columns[OVSREC_QUEUE_N_COLUMNS];

static void
ovsrec_queue_columns_init(void)
{
    struct ovsdb_idl_column *c;

    /* Initialize ovsrec_queue_col_external_ids. */
    c = &ovsrec_queue_col_external_ids;
    c->name = "external_ids";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_STRING);
    c->type.key.u.string.minLen = 0;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_STRING);
    c->type.value.u.string.minLen = 0;
    c->type.n_min = 0;
    c->type.n_max = UINT_MAX;
    c->parse = ovsrec_queue_parse_external_ids;
    c->unparse = ovsrec_queue_unparse_external_ids;

    /* Initialize ovsrec_queue_col_other_config. */
    c = &ovsrec_queue_col_other_config;
    c->name = "other_config";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_STRING);
    c->type.key.u.string.minLen = 0;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_STRING);
    c->type.value.u.string.minLen = 0;
    c->type.n_min = 0;
    c->type.n_max = UINT_MAX;
    c->parse = ovsrec_queue_parse_other_config;
    c->unparse = ovsrec_queue_unparse_other_config;
}

/* SSL table. */

static void
ovsrec_ssl_parse_bootstrap_ca_cert(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_ssl *row = ovsrec_ssl_cast(row_);

    assert(inited);
    if (datum->n >= 1) {
        row->bootstrap_ca_cert = datum->keys[0].boolean;
    } else {
        row->bootstrap_ca_cert = false;
    }
}

static void
ovsrec_ssl_parse_ca_cert(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_ssl *row = ovsrec_ssl_cast(row_);

    assert(inited);
    if (datum->n >= 1) {
        row->ca_cert = datum->keys[0].string;
    } else {
        row->ca_cert = "";
    }
}

static void
ovsrec_ssl_parse_certificate(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_ssl *row = ovsrec_ssl_cast(row_);

    assert(inited);
    if (datum->n >= 1) {
        row->certificate = datum->keys[0].string;
    } else {
        row->certificate = "";
    }
}

static void
ovsrec_ssl_parse_external_ids(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_ssl *row = ovsrec_ssl_cast(row_);
    size_t i;

    assert(inited);
    row->key_external_ids = NULL;
    row->value_external_ids = NULL;
    row->n_external_ids = 0;
    for (i = 0; i < datum->n; i++) {
        if (!row->n_external_ids) {
            row->key_external_ids = xmalloc(datum->n * sizeof *row->key_external_ids);
            row->value_external_ids = xmalloc(datum->n * sizeof *row->value_external_ids);
        }
        row->key_external_ids[row->n_external_ids] = datum->keys[i].string;
        row->value_external_ids[row->n_external_ids] = datum->values[i].string;
        row->n_external_ids++;
    }
}

static void
ovsrec_ssl_parse_private_key(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_ssl *row = ovsrec_ssl_cast(row_);

    assert(inited);
    if (datum->n >= 1) {
        row->private_key = datum->keys[0].string;
    } else {
        row->private_key = "";
    }
}

static void
ovsrec_ssl_unparse_bootstrap_ca_cert(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
ovsrec_ssl_unparse_ca_cert(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
ovsrec_ssl_unparse_certificate(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
ovsrec_ssl_unparse_external_ids(struct ovsdb_idl_row *row_)
{
    struct ovsrec_ssl *row = ovsrec_ssl_cast(row_);

    assert(inited);
    free(row->key_external_ids);
    free(row->value_external_ids);
}

static void
ovsrec_ssl_unparse_private_key(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

const struct ovsrec_ssl *
ovsrec_ssl_first(const struct ovsdb_idl *idl)
{
    return ovsrec_ssl_cast(ovsdb_idl_first_row(idl, &ovsrec_table_classes[OVSREC_TABLE_SSL]));
}

const struct ovsrec_ssl *
ovsrec_ssl_next(const struct ovsrec_ssl *row)
{
    return ovsrec_ssl_cast(ovsdb_idl_next_row(&row->header_));
}

void
ovsrec_ssl_delete(const struct ovsrec_ssl *row)
{
    ovsdb_idl_txn_delete(&row->header_);
}

struct ovsrec_ssl *
ovsrec_ssl_insert(struct ovsdb_idl_txn *txn)
{
    return ovsrec_ssl_cast(ovsdb_idl_txn_insert(txn, &ovsrec_table_classes[OVSREC_TABLE_SSL], NULL));
}


void
ovsrec_ssl_verify_bootstrap_ca_cert(const struct ovsrec_ssl *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_ssl_columns[OVSREC_SSL_COL_BOOTSTRAP_CA_CERT]);
}

void
ovsrec_ssl_verify_ca_cert(const struct ovsrec_ssl *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_ssl_columns[OVSREC_SSL_COL_CA_CERT]);
}

void
ovsrec_ssl_verify_certificate(const struct ovsrec_ssl *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_ssl_columns[OVSREC_SSL_COL_CERTIFICATE]);
}

void
ovsrec_ssl_verify_external_ids(const struct ovsrec_ssl *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_ssl_columns[OVSREC_SSL_COL_EXTERNAL_IDS]);
}

void
ovsrec_ssl_verify_private_key(const struct ovsrec_ssl *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_ssl_columns[OVSREC_SSL_COL_PRIVATE_KEY]);
}

/* Returns the bootstrap_ca_cert column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_BOOLEAN.
 * (This helps to avoid silent bugs if someone changes bootstrap_ca_cert's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_ssl_get_bootstrap_ca_cert(const struct ovsrec_ssl *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_BOOLEAN);
    return ovsdb_idl_read(&row->header_, &ovsrec_ssl_col_bootstrap_ca_cert);
}

/* Returns the ca_cert column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes ca_cert's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_ssl_get_ca_cert(const struct ovsrec_ssl *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &ovsrec_ssl_col_ca_cert);
}

/* Returns the certificate column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes certificate's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_ssl_get_certificate(const struct ovsrec_ssl *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &ovsrec_ssl_col_certificate);
}

/* Returns the external_ids column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * 'value_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes external_ids's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_ssl_get_external_ids(const struct ovsrec_ssl *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED,
	enum ovsdb_atomic_type value_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_STRING);
    assert(value_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &ovsrec_ssl_col_external_ids);
}

/* Returns the private_key column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes private_key's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_ssl_get_private_key(const struct ovsrec_ssl *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &ovsrec_ssl_col_private_key);
}

void
ovsrec_ssl_set_bootstrap_ca_cert(const struct ovsrec_ssl *row, bool bootstrap_ca_cert)
{
    struct ovsdb_datum datum;

    assert(inited);
    datum.n = 1;
    datum.keys = xmalloc(sizeof *datum.keys);
    datum.keys[0].boolean = bootstrap_ca_cert;
    datum.values = NULL;
    ovsdb_idl_txn_write(&row->header_, &ovsrec_ssl_columns[OVSREC_SSL_COL_BOOTSTRAP_CA_CERT], &datum);
}

void
ovsrec_ssl_set_ca_cert(const struct ovsrec_ssl *row, const char *ca_cert)
{
    struct ovsdb_datum datum;

    assert(inited);
    datum.n = 1;
    datum.keys = xmalloc(sizeof *datum.keys);
    datum.keys[0].string = xstrdup(ca_cert);
    datum.values = NULL;
    ovsdb_idl_txn_write(&row->header_, &ovsrec_ssl_columns[OVSREC_SSL_COL_CA_CERT], &datum);
}

void
ovsrec_ssl_set_certificate(const struct ovsrec_ssl *row, const char *certificate)
{
    struct ovsdb_datum datum;

    assert(inited);
    datum.n = 1;
    datum.keys = xmalloc(sizeof *datum.keys);
    datum.keys[0].string = xstrdup(certificate);
    datum.values = NULL;
    ovsdb_idl_txn_write(&row->header_, &ovsrec_ssl_columns[OVSREC_SSL_COL_CERTIFICATE], &datum);
}

void
ovsrec_ssl_set_external_ids(const struct ovsrec_ssl *row, char **key_external_ids, char **value_external_ids, size_t n_external_ids)
{
    struct ovsdb_datum datum;
    size_t i;

    assert(inited);
    datum.n = n_external_ids;
    datum.keys = xmalloc(n_external_ids * sizeof *datum.keys);
    datum.values = xmalloc(n_external_ids * sizeof *datum.values);
    for (i = 0; i < n_external_ids; i++) {
        datum.keys[i].string = xstrdup(key_external_ids[i]);
        datum.values[i].string = xstrdup(value_external_ids[i]);
    }
    ovsdb_datum_sort_unique(&datum, OVSDB_TYPE_STRING, OVSDB_TYPE_STRING);
    ovsdb_idl_txn_write(&row->header_, &ovsrec_ssl_columns[OVSREC_SSL_COL_EXTERNAL_IDS], &datum);
}

void
ovsrec_ssl_set_private_key(const struct ovsrec_ssl *row, const char *private_key)
{
    struct ovsdb_datum datum;

    assert(inited);
    datum.n = 1;
    datum.keys = xmalloc(sizeof *datum.keys);
    datum.keys[0].string = xstrdup(private_key);
    datum.values = NULL;
    ovsdb_idl_txn_write(&row->header_, &ovsrec_ssl_columns[OVSREC_SSL_COL_PRIVATE_KEY], &datum);
}

struct ovsdb_idl_column ovsrec_ssl_columns[OVSREC_SSL_N_COLUMNS];

static void
ovsrec_ssl_columns_init(void)
{
    struct ovsdb_idl_column *c;

    /* Initialize ovsrec_ssl_col_bootstrap_ca_cert. */
    c = &ovsrec_ssl_col_bootstrap_ca_cert;
    c->name = "bootstrap_ca_cert";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_BOOLEAN);
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 1;
    c->type.n_max = 1;
    c->parse = ovsrec_ssl_parse_bootstrap_ca_cert;
    c->unparse = ovsrec_ssl_unparse_bootstrap_ca_cert;

    /* Initialize ovsrec_ssl_col_ca_cert. */
    c = &ovsrec_ssl_col_ca_cert;
    c->name = "ca_cert";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_STRING);
    c->type.key.u.string.minLen = 0;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 1;
    c->type.n_max = 1;
    c->parse = ovsrec_ssl_parse_ca_cert;
    c->unparse = ovsrec_ssl_unparse_ca_cert;

    /* Initialize ovsrec_ssl_col_certificate. */
    c = &ovsrec_ssl_col_certificate;
    c->name = "certificate";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_STRING);
    c->type.key.u.string.minLen = 0;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 1;
    c->type.n_max = 1;
    c->parse = ovsrec_ssl_parse_certificate;
    c->unparse = ovsrec_ssl_unparse_certificate;

    /* Initialize ovsrec_ssl_col_external_ids. */
    c = &ovsrec_ssl_col_external_ids;
    c->name = "external_ids";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_STRING);
    c->type.key.u.string.minLen = 0;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_STRING);
    c->type.value.u.string.minLen = 0;
    c->type.n_min = 0;
    c->type.n_max = UINT_MAX;
    c->parse = ovsrec_ssl_parse_external_ids;
    c->unparse = ovsrec_ssl_unparse_external_ids;

    /* Initialize ovsrec_ssl_col_private_key. */
    c = &ovsrec_ssl_col_private_key;
    c->name = "private_key";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_STRING);
    c->type.key.u.string.minLen = 0;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 1;
    c->type.n_max = 1;
    c->parse = ovsrec_ssl_parse_private_key;
    c->unparse = ovsrec_ssl_unparse_private_key;
}

/* sFlow table. */

static void
ovsrec_sflow_parse_agent(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_sflow *row = ovsrec_sflow_cast(row_);

    assert(inited);
    if (datum->n >= 1) {
        row->agent = datum->keys[0].string;
    } else {
        row->agent = NULL;
    }
}

static void
ovsrec_sflow_parse_external_ids(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_sflow *row = ovsrec_sflow_cast(row_);
    size_t i;

    assert(inited);
    row->key_external_ids = NULL;
    row->value_external_ids = NULL;
    row->n_external_ids = 0;
    for (i = 0; i < datum->n; i++) {
        if (!row->n_external_ids) {
            row->key_external_ids = xmalloc(datum->n * sizeof *row->key_external_ids);
            row->value_external_ids = xmalloc(datum->n * sizeof *row->value_external_ids);
        }
        row->key_external_ids[row->n_external_ids] = datum->keys[i].string;
        row->value_external_ids[row->n_external_ids] = datum->values[i].string;
        row->n_external_ids++;
    }
}

static void
ovsrec_sflow_parse_header(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_sflow *row = ovsrec_sflow_cast(row_);
    size_t n = MIN(1, datum->n);
    size_t i;

    assert(inited);
    row->header = NULL;
    row->n_header = 0;
    for (i = 0; i < n; i++) {
        if (!row->n_header) {
            row->header = xmalloc(n * sizeof *row->header);
        }
        row->header[row->n_header] = datum->keys[i].integer;
        row->n_header++;
    }
}

static void
ovsrec_sflow_parse_polling(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_sflow *row = ovsrec_sflow_cast(row_);
    size_t n = MIN(1, datum->n);
    size_t i;

    assert(inited);
    row->polling = NULL;
    row->n_polling = 0;
    for (i = 0; i < n; i++) {
        if (!row->n_polling) {
            row->polling = xmalloc(n * sizeof *row->polling);
        }
        row->polling[row->n_polling] = datum->keys[i].integer;
        row->n_polling++;
    }
}

static void
ovsrec_sflow_parse_sampling(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_sflow *row = ovsrec_sflow_cast(row_);
    size_t n = MIN(1, datum->n);
    size_t i;

    assert(inited);
    row->sampling = NULL;
    row->n_sampling = 0;
    for (i = 0; i < n; i++) {
        if (!row->n_sampling) {
            row->sampling = xmalloc(n * sizeof *row->sampling);
        }
        row->sampling[row->n_sampling] = datum->keys[i].integer;
        row->n_sampling++;
    }
}

static void
ovsrec_sflow_parse_targets(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct ovsrec_sflow *row = ovsrec_sflow_cast(row_);
    size_t i;

    assert(inited);
    row->targets = NULL;
    row->n_targets = 0;
    for (i = 0; i < datum->n; i++) {
        if (!row->n_targets) {
            row->targets = xmalloc(datum->n * sizeof *row->targets);
        }
        row->targets[row->n_targets] = datum->keys[i].string;
        row->n_targets++;
    }
}

static void
ovsrec_sflow_unparse_agent(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
ovsrec_sflow_unparse_external_ids(struct ovsdb_idl_row *row_)
{
    struct ovsrec_sflow *row = ovsrec_sflow_cast(row_);

    assert(inited);
    free(row->key_external_ids);
    free(row->value_external_ids);
}

static void
ovsrec_sflow_unparse_header(struct ovsdb_idl_row *row_)
{
    struct ovsrec_sflow *row = ovsrec_sflow_cast(row_);

    assert(inited);
    free(row->header);
}

static void
ovsrec_sflow_unparse_polling(struct ovsdb_idl_row *row_)
{
    struct ovsrec_sflow *row = ovsrec_sflow_cast(row_);

    assert(inited);
    free(row->polling);
}

static void
ovsrec_sflow_unparse_sampling(struct ovsdb_idl_row *row_)
{
    struct ovsrec_sflow *row = ovsrec_sflow_cast(row_);

    assert(inited);
    free(row->sampling);
}

static void
ovsrec_sflow_unparse_targets(struct ovsdb_idl_row *row_)
{
    struct ovsrec_sflow *row = ovsrec_sflow_cast(row_);

    assert(inited);
    free(row->targets);
}

const struct ovsrec_sflow *
ovsrec_sflow_first(const struct ovsdb_idl *idl)
{
    return ovsrec_sflow_cast(ovsdb_idl_first_row(idl, &ovsrec_table_classes[OVSREC_TABLE_SFLOW]));
}

const struct ovsrec_sflow *
ovsrec_sflow_next(const struct ovsrec_sflow *row)
{
    return ovsrec_sflow_cast(ovsdb_idl_next_row(&row->header_));
}

void
ovsrec_sflow_delete(const struct ovsrec_sflow *row)
{
    ovsdb_idl_txn_delete(&row->header_);
}

struct ovsrec_sflow *
ovsrec_sflow_insert(struct ovsdb_idl_txn *txn)
{
    return ovsrec_sflow_cast(ovsdb_idl_txn_insert(txn, &ovsrec_table_classes[OVSREC_TABLE_SFLOW], NULL));
}


void
ovsrec_sflow_verify_agent(const struct ovsrec_sflow *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_sflow_columns[OVSREC_SFLOW_COL_AGENT]);
}

void
ovsrec_sflow_verify_external_ids(const struct ovsrec_sflow *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_sflow_columns[OVSREC_SFLOW_COL_EXTERNAL_IDS]);
}

void
ovsrec_sflow_verify_header(const struct ovsrec_sflow *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_sflow_columns[OVSREC_SFLOW_COL_HEADER]);
}

void
ovsrec_sflow_verify_polling(const struct ovsrec_sflow *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_sflow_columns[OVSREC_SFLOW_COL_POLLING]);
}

void
ovsrec_sflow_verify_sampling(const struct ovsrec_sflow *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_sflow_columns[OVSREC_SFLOW_COL_SAMPLING]);
}

void
ovsrec_sflow_verify_targets(const struct ovsrec_sflow *row)
{
    assert(inited);
    ovsdb_idl_txn_verify(&row->header_, &ovsrec_sflow_columns[OVSREC_SFLOW_COL_TARGETS]);
}

/* Returns the agent column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes agent's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_sflow_get_agent(const struct ovsrec_sflow *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &ovsrec_sflow_col_agent);
}

/* Returns the external_ids column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * 'value_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes external_ids's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_sflow_get_external_ids(const struct ovsrec_sflow *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED,
	enum ovsdb_atomic_type value_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_STRING);
    assert(value_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &ovsrec_sflow_col_external_ids);
}

/* Returns the header column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_INTEGER.
 * (This helps to avoid silent bugs if someone changes header's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_sflow_get_header(const struct ovsrec_sflow *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_INTEGER);
    return ovsdb_idl_read(&row->header_, &ovsrec_sflow_col_header);
}

/* Returns the polling column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_INTEGER.
 * (This helps to avoid silent bugs if someone changes polling's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_sflow_get_polling(const struct ovsrec_sflow *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_INTEGER);
    return ovsdb_idl_read(&row->header_, &ovsrec_sflow_col_polling);
}

/* Returns the sampling column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_INTEGER.
 * (This helps to avoid silent bugs if someone changes sampling's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_sflow_get_sampling(const struct ovsrec_sflow *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_INTEGER);
    return ovsdb_idl_read(&row->header_, &ovsrec_sflow_col_sampling);
}

/* Returns the targets column's value in 'row' as a struct ovsdb_datum.
 * This is useful occasionally: for example, ovsdb_datum_find_key() is an
 * easier and more efficient way to search for a given key than implementing
 * the same operation on the "cooked" form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes targets's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone(). */
const struct ovsdb_datum *
ovsrec_sflow_get_targets(const struct ovsrec_sflow *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    assert(key_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &ovsrec_sflow_col_targets);
}

void
ovsrec_sflow_set_agent(const struct ovsrec_sflow *row, const char *agent)
{
    struct ovsdb_datum datum;

    assert(inited);
    if (agent) {
        datum.n = 1;
        datum.keys = xmalloc(sizeof *datum.keys);
        datum.keys[0].string = xstrdup(agent);
    } else {
        datum.n = 0;
        datum.keys = NULL;
    }
    datum.values = NULL;
    ovsdb_idl_txn_write(&row->header_, &ovsrec_sflow_columns[OVSREC_SFLOW_COL_AGENT], &datum);
}

void
ovsrec_sflow_set_external_ids(const struct ovsrec_sflow *row, char **key_external_ids, char **value_external_ids, size_t n_external_ids)
{
    struct ovsdb_datum datum;
    size_t i;

    assert(inited);
    datum.n = n_external_ids;
    datum.keys = xmalloc(n_external_ids * sizeof *datum.keys);
    datum.values = xmalloc(n_external_ids * sizeof *datum.values);
    for (i = 0; i < n_external_ids; i++) {
        datum.keys[i].string = xstrdup(key_external_ids[i]);
        datum.values[i].string = xstrdup(value_external_ids[i]);
    }
    ovsdb_datum_sort_unique(&datum, OVSDB_TYPE_STRING, OVSDB_TYPE_STRING);
    ovsdb_idl_txn_write(&row->header_, &ovsrec_sflow_columns[OVSREC_SFLOW_COL_EXTERNAL_IDS], &datum);
}

void
ovsrec_sflow_set_header(const struct ovsrec_sflow *row, const int64_t *header, size_t n_header)
{
    struct ovsdb_datum datum;
    size_t i;

    assert(inited);
    datum.n = n_header;
    datum.keys = xmalloc(n_header * sizeof *datum.keys);
    datum.values = NULL;
    for (i = 0; i < n_header; i++) {
        datum.keys[i].integer = header[i];
    }
    ovsdb_datum_sort_unique(&datum, OVSDB_TYPE_INTEGER, OVSDB_TYPE_VOID);
    ovsdb_idl_txn_write(&row->header_, &ovsrec_sflow_columns[OVSREC_SFLOW_COL_HEADER], &datum);
}

void
ovsrec_sflow_set_polling(const struct ovsrec_sflow *row, const int64_t *polling, size_t n_polling)
{
    struct ovsdb_datum datum;
    size_t i;

    assert(inited);
    datum.n = n_polling;
    datum.keys = xmalloc(n_polling * sizeof *datum.keys);
    datum.values = NULL;
    for (i = 0; i < n_polling; i++) {
        datum.keys[i].integer = polling[i];
    }
    ovsdb_datum_sort_unique(&datum, OVSDB_TYPE_INTEGER, OVSDB_TYPE_VOID);
    ovsdb_idl_txn_write(&row->header_, &ovsrec_sflow_columns[OVSREC_SFLOW_COL_POLLING], &datum);
}

void
ovsrec_sflow_set_sampling(const struct ovsrec_sflow *row, const int64_t *sampling, size_t n_sampling)
{
    struct ovsdb_datum datum;
    size_t i;

    assert(inited);
    datum.n = n_sampling;
    datum.keys = xmalloc(n_sampling * sizeof *datum.keys);
    datum.values = NULL;
    for (i = 0; i < n_sampling; i++) {
        datum.keys[i].integer = sampling[i];
    }
    ovsdb_datum_sort_unique(&datum, OVSDB_TYPE_INTEGER, OVSDB_TYPE_VOID);
    ovsdb_idl_txn_write(&row->header_, &ovsrec_sflow_columns[OVSREC_SFLOW_COL_SAMPLING], &datum);
}

void
ovsrec_sflow_set_targets(const struct ovsrec_sflow *row, char **targets, size_t n_targets)
{
    struct ovsdb_datum datum;
    size_t i;

    assert(inited);
    datum.n = n_targets;
    datum.keys = xmalloc(n_targets * sizeof *datum.keys);
    datum.values = NULL;
    for (i = 0; i < n_targets; i++) {
        datum.keys[i].string = xstrdup(targets[i]);
    }
    ovsdb_datum_sort_unique(&datum, OVSDB_TYPE_STRING, OVSDB_TYPE_VOID);
    ovsdb_idl_txn_write(&row->header_, &ovsrec_sflow_columns[OVSREC_SFLOW_COL_TARGETS], &datum);
}

struct ovsdb_idl_column ovsrec_sflow_columns[OVSREC_SFLOW_N_COLUMNS];

static void
ovsrec_sflow_columns_init(void)
{
    struct ovsdb_idl_column *c;

    /* Initialize ovsrec_sflow_col_agent. */
    c = &ovsrec_sflow_col_agent;
    c->name = "agent";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_STRING);
    c->type.key.u.string.minLen = 0;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 0;
    c->type.n_max = 1;
    c->parse = ovsrec_sflow_parse_agent;
    c->unparse = ovsrec_sflow_unparse_agent;

    /* Initialize ovsrec_sflow_col_external_ids. */
    c = &ovsrec_sflow_col_external_ids;
    c->name = "external_ids";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_STRING);
    c->type.key.u.string.minLen = 0;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_STRING);
    c->type.value.u.string.minLen = 0;
    c->type.n_min = 0;
    c->type.n_max = UINT_MAX;
    c->parse = ovsrec_sflow_parse_external_ids;
    c->unparse = ovsrec_sflow_unparse_external_ids;

    /* Initialize ovsrec_sflow_col_header. */
    c = &ovsrec_sflow_col_header;
    c->name = "header";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_INTEGER);
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 0;
    c->type.n_max = 1;
    c->parse = ovsrec_sflow_parse_header;
    c->unparse = ovsrec_sflow_unparse_header;

    /* Initialize ovsrec_sflow_col_polling. */
    c = &ovsrec_sflow_col_polling;
    c->name = "polling";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_INTEGER);
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 0;
    c->type.n_max = 1;
    c->parse = ovsrec_sflow_parse_polling;
    c->unparse = ovsrec_sflow_unparse_polling;

    /* Initialize ovsrec_sflow_col_sampling. */
    c = &ovsrec_sflow_col_sampling;
    c->name = "sampling";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_INTEGER);
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 0;
    c->type.n_max = 1;
    c->parse = ovsrec_sflow_parse_sampling;
    c->unparse = ovsrec_sflow_unparse_sampling;

    /* Initialize ovsrec_sflow_col_targets. */
    c = &ovsrec_sflow_col_targets;
    c->name = "targets";
    ovsdb_base_type_init(&c->type.key, OVSDB_TYPE_STRING);
    c->type.key.u.string.minLen = 0;
    ovsdb_base_type_init(&c->type.value, OVSDB_TYPE_VOID);
    c->type.n_min = 1;
    c->type.n_max = UINT_MAX;
    c->parse = ovsrec_sflow_parse_targets;
    c->unparse = ovsrec_sflow_unparse_targets;
}

struct ovsdb_idl_table_class ovsrec_table_classes[OVSREC_N_TABLES] = {
    {"Bridge", false,
     ovsrec_bridge_columns, ARRAY_SIZE(ovsrec_bridge_columns),
     sizeof(struct ovsrec_bridge)},
    {"Capability", false,
     ovsrec_capability_columns, ARRAY_SIZE(ovsrec_capability_columns),
     sizeof(struct ovsrec_capability)},
    {"Controller", false,
     ovsrec_controller_columns, ARRAY_SIZE(ovsrec_controller_columns),
     sizeof(struct ovsrec_controller)},
    {"Interface", false,
     ovsrec_interface_columns, ARRAY_SIZE(ovsrec_interface_columns),
     sizeof(struct ovsrec_interface)},
    {"Manager", false,
     ovsrec_manager_columns, ARRAY_SIZE(ovsrec_manager_columns),
     sizeof(struct ovsrec_manager)},
    {"Mirror", false,
     ovsrec_mirror_columns, ARRAY_SIZE(ovsrec_mirror_columns),
     sizeof(struct ovsrec_mirror)},
    {"NetFlow", false,
     ovsrec_netflow_columns, ARRAY_SIZE(ovsrec_netflow_columns),
     sizeof(struct ovsrec_netflow)},
    {"Open_vSwitch", true,
     ovsrec_open_vswitch_columns, ARRAY_SIZE(ovsrec_open_vswitch_columns),
     sizeof(struct ovsrec_open_vswitch)},
    {"Port", false,
     ovsrec_port_columns, ARRAY_SIZE(ovsrec_port_columns),
     sizeof(struct ovsrec_port)},
    {"QoS", true,
     ovsrec_qos_columns, ARRAY_SIZE(ovsrec_qos_columns),
     sizeof(struct ovsrec_qos)},
    {"Queue", true,
     ovsrec_queue_columns, ARRAY_SIZE(ovsrec_queue_columns),
     sizeof(struct ovsrec_queue)},
    {"SSL", false,
     ovsrec_ssl_columns, ARRAY_SIZE(ovsrec_ssl_columns),
     sizeof(struct ovsrec_ssl)},
    {"sFlow", false,
     ovsrec_sflow_columns, ARRAY_SIZE(ovsrec_sflow_columns),
     sizeof(struct ovsrec_sflow)},
};

struct ovsdb_idl_class ovsrec_idl_class = {
    "Open_vSwitch", ovsrec_table_classes, ARRAY_SIZE(ovsrec_table_classes)
};

void
ovsrec_init(void)
{
    if (inited) {
        return;
    }
    inited = true;

    ovsrec_bridge_columns_init();
    ovsrec_capability_columns_init();
    ovsrec_controller_columns_init();
    ovsrec_interface_columns_init();
    ovsrec_manager_columns_init();
    ovsrec_mirror_columns_init();
    ovsrec_netflow_columns_init();
    ovsrec_open_vswitch_columns_init();
    ovsrec_port_columns_init();
    ovsrec_qos_columns_init();
    ovsrec_queue_columns_init();
    ovsrec_ssl_columns_init();
    ovsrec_sflow_columns_init();
}
