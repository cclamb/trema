/*
 * Copyright (c) 2008, 2009, 2010, 2011 Nicira Networks.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at:
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef PACKETS_H
#define PACKETS_H 1

#include <inttypes.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <stdint.h>
#include <string.h>
#include "compiler.h"
#include "openvswitch/types.h"
#include "random.h"
#include "util.h"

struct ofpbuf;
struct ds;

bool dpid_from_string(const char *s, uint64_t *dpidp);

#define ETH_ADDR_LEN           6

static const uint8_t eth_addr_broadcast[ETH_ADDR_LEN] OVS_UNUSED
    = { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff };

static const uint8_t eth_addr_stp[ETH_ADDR_LEN] OVS_UNUSED
    = { 0x01, 0x80, 0xC2, 0x00, 0x00, 0x01 };

static const uint8_t eth_addr_lacp[ETH_ADDR_LEN] OVS_UNUSED
    = { 0x01, 0x80, 0xC2, 0x00, 0x00, 0x02 };

static inline bool eth_addr_is_broadcast(const uint8_t ea[6])
{
    return (ea[0] & ea[1] & ea[2] & ea[3] & ea[4] & ea[5]) == 0xff;
}

static inline bool eth_addr_is_multicast(const uint8_t ea[6])
{
    return ea[0] & 1;
}
static inline bool eth_addr_is_local(const uint8_t ea[6])
{
    /* Local if it is either a locally administered address or a Nicira random
     * address. */
    return ea[0] & 2
       || (ea[0] == 0x00 && ea[1] == 0x23 && ea[2] == 0x20 && ea[3] & 0x80);
}
static inline bool eth_addr_is_zero(const uint8_t ea[6])
{
    return !(ea[0] | ea[1] | ea[2] | ea[3] | ea[4] | ea[5]);
}
static inline int eth_addr_compare_3way(const uint8_t a[ETH_ADDR_LEN],
                                        const uint8_t b[ETH_ADDR_LEN])
{
    return memcmp(a, b, ETH_ADDR_LEN);
}
static inline bool eth_addr_equals(const uint8_t a[ETH_ADDR_LEN],
                                   const uint8_t b[ETH_ADDR_LEN])
{
    return !eth_addr_compare_3way(a, b);
}
static inline uint64_t eth_addr_to_uint64(const uint8_t ea[ETH_ADDR_LEN])
{
    return (((uint64_t) ea[0] << 40)
            | ((uint64_t) ea[1] << 32)
            | ((uint64_t) ea[2] << 24)
            | ((uint64_t) ea[3] << 16)
            | ((uint64_t) ea[4] << 8)
            | ea[5]);
}
static inline void eth_addr_from_uint64(uint64_t x, uint8_t ea[ETH_ADDR_LEN])
{
    ea[0] = x >> 40;
    ea[1] = x >> 32;
    ea[2] = x >> 24;
    ea[3] = x >> 16;
    ea[4] = x >> 8;
    ea[5] = x;
}
static inline void eth_addr_mark_random(uint8_t ea[ETH_ADDR_LEN])
{
    ea[0] &= ~1;                /* Unicast. */
    ea[0] |= 2;                 /* Private. */
}
static inline void eth_addr_random(uint8_t ea[ETH_ADDR_LEN])
{
    random_bytes(ea, ETH_ADDR_LEN);
    eth_addr_mark_random(ea);
}
static inline void eth_addr_nicira_random(uint8_t ea[ETH_ADDR_LEN])
{
    eth_addr_random(ea);

    /* Set the OUI to the Nicira one. */
    ea[0] = 0x00;
    ea[1] = 0x23;
    ea[2] = 0x20;

    /* Set the top bit to indicate random Nicira address. */
    ea[3] |= 0x80;
}
/* Returns true if 'ea' is a reserved multicast address, that a bridge must
 * never forward, false otherwise. */
static inline bool eth_addr_is_reserved(const uint8_t ea[ETH_ADDR_LEN])
{
    return (ea[0] == 0x01
            && ea[1] == 0x80
            && ea[2] == 0xc2
            && ea[3] == 0x00
            && ea[4] == 0x00
            && (ea[5] & 0xf0) == 0x00);
}

bool eth_addr_from_string(const char *, uint8_t ea[ETH_ADDR_LEN]);

void compose_benign_packet(struct ofpbuf *, const char *tag,
                           uint16_t snap_type,
                           const uint8_t eth_src[ETH_ADDR_LEN]);

void eth_set_vlan_tci(struct ofpbuf *, ovs_be16 tci);

/* Example:
 *
 * uint8_t mac[ETH_ADDR_LEN];
 *    [...]
 * printf("The Ethernet address is "ETH_ADDR_FMT"\n", ETH_ADDR_ARGS(mac));
 *
 */
#define ETH_ADDR_FMT                                                    \
    "%02"PRIx8":%02"PRIx8":%02"PRIx8":%02"PRIx8":%02"PRIx8":%02"PRIx8
#define ETH_ADDR_ARGS(ea)                                   \
    (ea)[0], (ea)[1], (ea)[2], (ea)[3], (ea)[4], (ea)[5]

/* Example:
 *
 * char *string = "1 00:11:22:33:44:55 2";
 * uint8_t mac[ETH_ADDR_LEN];
 * int a, b;
 *
 * if (sscanf(string, "%d"ETH_ADDR_SCAN_FMT"%d",
 *     &a, ETH_ADDR_SCAN_ARGS(mac), &b) == 1 + ETH_ADDR_SCAN_COUNT + 1) {
 *     ...
 * }
 */
#define ETH_ADDR_SCAN_FMT "%"SCNx8":%"SCNx8":%"SCNx8":%"SCNx8":%"SCNx8":%"SCNx8
#define ETH_ADDR_SCAN_ARGS(ea) \
        &(ea)[0], &(ea)[1], &(ea)[2], &(ea)[3], &(ea)[4], &(ea)[5]
#define ETH_ADDR_SCAN_COUNT 6

#define ETH_TYPE_IP            0x0800
#define ETH_TYPE_ARP           0x0806
#define ETH_TYPE_VLAN          0x8100
#define ETH_TYPE_IPV6          0x86dd
#define ETH_TYPE_LACP          0x8809

/* Minimum value for an Ethernet type.  Values below this are IEEE 802.2 frame
 * lengths. */
#define ETH_TYPE_MIN           0x600

#define ETH_HEADER_LEN 14
#define ETH_PAYLOAD_MIN 46
#define ETH_PAYLOAD_MAX 1500
#define ETH_TOTAL_MIN (ETH_HEADER_LEN + ETH_PAYLOAD_MIN)
#define ETH_TOTAL_MAX (ETH_HEADER_LEN + ETH_PAYLOAD_MAX)
#define ETH_VLAN_TOTAL_MAX (ETH_HEADER_LEN + VLAN_HEADER_LEN + ETH_PAYLOAD_MAX)
struct eth_header {
    uint8_t eth_dst[ETH_ADDR_LEN];
    uint8_t eth_src[ETH_ADDR_LEN];
    ovs_be16 eth_type;
} __attribute__((packed));
BUILD_ASSERT_DECL(ETH_HEADER_LEN == sizeof(struct eth_header));

#define LLC_DSAP_SNAP 0xaa
#define LLC_SSAP_SNAP 0xaa
#define LLC_CNTL_SNAP 3

#define LLC_HEADER_LEN 3
struct llc_header {
    uint8_t llc_dsap;
    uint8_t llc_ssap;
    uint8_t llc_cntl;
} __attribute__((packed));
BUILD_ASSERT_DECL(LLC_HEADER_LEN == sizeof(struct llc_header));

#define SNAP_ORG_ETHERNET "\0\0" /* The compiler adds a null byte, so
                                    sizeof(SNAP_ORG_ETHERNET) == 3. */
#define SNAP_HEADER_LEN 5
struct snap_header {
    uint8_t snap_org[3];
    ovs_be16 snap_type;
} __attribute__((packed));
BUILD_ASSERT_DECL(SNAP_HEADER_LEN == sizeof(struct snap_header));

#define LLC_SNAP_HEADER_LEN (LLC_HEADER_LEN + SNAP_HEADER_LEN)
struct llc_snap_header {
    struct llc_header llc;
    struct snap_header snap;
} __attribute__((packed));
BUILD_ASSERT_DECL(LLC_SNAP_HEADER_LEN == sizeof(struct llc_snap_header));

#define VLAN_VID_MASK 0x0fff
#define VLAN_VID_SHIFT 0

#define VLAN_PCP_MASK 0xe000
#define VLAN_PCP_SHIFT 13

#define VLAN_CFI 0x1000

/* Given the vlan_tci field from an 802.1Q header, in network byte order,
 * returns the VLAN ID in host byte order. */
static inline uint16_t
vlan_tci_to_vid(ovs_be16 vlan_tci)
{
    return (ntohs(vlan_tci) & VLAN_VID_MASK) >> VLAN_VID_SHIFT;
}

/* Given the vlan_tci field from an 802.1Q header, in network byte order,
 * returns the priority code point (PCP) in host byte order. */
static inline int
vlan_tci_to_pcp(ovs_be16 vlan_tci)
{
    return (ntohs(vlan_tci) & VLAN_PCP_MASK) >> VLAN_PCP_SHIFT;
}

#define VLAN_HEADER_LEN 4
struct vlan_header {
    ovs_be16 vlan_tci;          /* Lowest 12 bits are VLAN ID. */
    ovs_be16 vlan_next_type;
};
BUILD_ASSERT_DECL(VLAN_HEADER_LEN == sizeof(struct vlan_header));

#define VLAN_ETH_HEADER_LEN (ETH_HEADER_LEN + VLAN_HEADER_LEN)
struct vlan_eth_header {
    uint8_t veth_dst[ETH_ADDR_LEN];
    uint8_t veth_src[ETH_ADDR_LEN];
    ovs_be16 veth_type;         /* Always htons(ETH_TYPE_VLAN). */
    ovs_be16 veth_tci;          /* Lowest 12 bits are VLAN ID. */
    ovs_be16 veth_next_type;
} __attribute__((packed));
BUILD_ASSERT_DECL(VLAN_ETH_HEADER_LEN == sizeof(struct vlan_eth_header));

/* The "(void) (ip)[0]" below has no effect on the value, since it's the first
 * argument of a comma expression, but it makes sure that 'ip' is a pointer.
 * This is useful since a common mistake is to pass an integer instead of a
 * pointer to IP_ARGS. */
#define IP_FMT "%"PRIu8".%"PRIu8".%"PRIu8".%"PRIu8
#define IP_ARGS(ip)                             \
        ((void) (ip)[0], ((uint8_t *) ip)[0]),  \
        ((uint8_t *) ip)[1],                    \
        ((uint8_t *) ip)[2],                    \
        ((uint8_t *) ip)[3]

/* Returns true if 'netmask' is a CIDR netmask, that is, if it consists of N
 * high-order 1-bits and 32-N low-order 0-bits. */
static inline bool
ip_is_cidr(ovs_be32 netmask)
{
    uint32_t x = ~ntohl(netmask);
    return !(x & (x + 1));
}

#define IP_VER(ip_ihl_ver) ((ip_ihl_ver) >> 4)
#define IP_IHL(ip_ihl_ver) ((ip_ihl_ver) & 15)
#define IP_IHL_VER(ihl, ver) (((ver) << 4) | (ihl))

/* TOS fields. */
#define IP_ECN_MASK 0x03
#define IP_DSCP_MASK 0xfc

#define IP_VERSION 4

#define IP_DONT_FRAGMENT  0x4000 /* Don't fragment. */
#define IP_MORE_FRAGMENTS 0x2000 /* More fragments. */
#define IP_FRAG_OFF_MASK  0x1fff /* Fragment offset. */
#define IP_IS_FRAGMENT(ip_frag_off) \
        ((ip_frag_off) & htons(IP_MORE_FRAGMENTS | IP_FRAG_OFF_MASK))

#define IP_HEADER_LEN 20
struct ip_header {
    uint8_t ip_ihl_ver;
    uint8_t ip_tos;
    ovs_be16 ip_tot_len;
    ovs_be16 ip_id;
    ovs_be16 ip_frag_off;
    uint8_t ip_ttl;
    uint8_t ip_proto;
    ovs_be16 ip_csum;
    ovs_be32 ip_src;
    ovs_be32 ip_dst;
};
BUILD_ASSERT_DECL(IP_HEADER_LEN == sizeof(struct ip_header));

#define ICMP_HEADER_LEN 4
struct icmp_header {
    uint8_t icmp_type;
    uint8_t icmp_code;
    ovs_be16 icmp_csum;
};
BUILD_ASSERT_DECL(ICMP_HEADER_LEN == sizeof(struct icmp_header));

#define UDP_HEADER_LEN 8
struct udp_header {
    ovs_be16 udp_src;
    ovs_be16 udp_dst;
    ovs_be16 udp_len;
    ovs_be16 udp_csum;
};
BUILD_ASSERT_DECL(UDP_HEADER_LEN == sizeof(struct udp_header));

#define TCP_FIN 0x01
#define TCP_SYN 0x02
#define TCP_RST 0x04
#define TCP_PSH 0x08
#define TCP_ACK 0x10
#define TCP_URG 0x20

#define TCP_FLAGS(tcp_ctl) (ntohs(tcp_ctl) & 0x003f)
#define TCP_OFFSET(tcp_ctl) (ntohs(tcp_ctl) >> 12)

#define TCP_HEADER_LEN 20
struct tcp_header {
    ovs_be16 tcp_src;
    ovs_be16 tcp_dst;
    ovs_be32 tcp_seq;
    ovs_be32 tcp_ack;
    ovs_be16 tcp_ctl;
    ovs_be16 tcp_winsz;
    ovs_be16 tcp_csum;
    ovs_be16 tcp_urg;
};
BUILD_ASSERT_DECL(TCP_HEADER_LEN == sizeof(struct tcp_header));

#define ARP_HRD_ETHERNET 1
#define ARP_PRO_IP 0x0800
#define ARP_OP_REQUEST 1
#define ARP_OP_REPLY 2

#define ARP_ETH_HEADER_LEN 28
struct arp_eth_header {
    /* Generic members. */
    ovs_be16 ar_hrd;           /* Hardware type. */
    ovs_be16 ar_pro;           /* Protocol type. */
    uint8_t ar_hln;            /* Hardware address length. */
    uint8_t ar_pln;            /* Protocol address length. */
    ovs_be16 ar_op;            /* Opcode. */

    /* Ethernet+IPv4 specific members. */
    uint8_t ar_sha[ETH_ADDR_LEN]; /* Sender hardware address. */
    ovs_be32 ar_spa;           /* Sender protocol address. */
    uint8_t ar_tha[ETH_ADDR_LEN]; /* Target hardware address. */
    ovs_be32 ar_tpa;           /* Target protocol address. */
} __attribute__((packed));
BUILD_ASSERT_DECL(ARP_ETH_HEADER_LEN == sizeof(struct arp_eth_header));

extern const struct in6_addr in6addr_exact;
#define IN6ADDR_EXACT_INIT { { { 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff, \
                                 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff } } }

static inline bool ipv6_addr_equals(const struct in6_addr *a,
                                    const struct in6_addr *b)
{
#ifdef IN6_ARE_ADDR_EQUAL
    return IN6_ARE_ADDR_EQUAL(a, b);
#else
    return !memcmp(a, b, sizeof(*a));
#endif
}

static inline bool ipv6_mask_is_any(const struct in6_addr *mask) {
    return ipv6_addr_equals(mask, &in6addr_any);
}

static inline bool ipv6_mask_is_exact(const struct in6_addr *mask) {
    return ipv6_addr_equals(mask, &in6addr_exact);
}

void format_ipv6_addr(char *addr_str, const struct in6_addr *addr);
void print_ipv6_addr(struct ds *string, const struct in6_addr *addr);
struct in6_addr ipv6_addr_bitand(const struct in6_addr *src,
                                 const struct in6_addr *mask);
struct in6_addr ipv6_create_mask(int mask);
int ipv6_count_cidr_bits(const struct in6_addr *netmask);
bool ipv6_is_cidr(const struct in6_addr *netmask);

void *eth_compose(struct ofpbuf *, const uint8_t eth_dst[ETH_ADDR_LEN],
                  const uint8_t eth_src[ETH_ADDR_LEN], uint16_t eth_type,
                  size_t size);
void *snap_compose(struct ofpbuf *, const uint8_t eth_dst[ETH_ADDR_LEN],
                   const uint8_t eth_src[ETH_ADDR_LEN],
                   unsigned int oui, uint16_t snap_type, size_t size);

#endif /* packets.h */
