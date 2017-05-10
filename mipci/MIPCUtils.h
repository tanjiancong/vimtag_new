//
//  MIPCUtils.h
//  ipcti
//
//  Created by MagicStudio on 12-8-5.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "mios_core_frameworks.h"

@class mjson_msg;

#if defined(__cplusplus)
extern "C" {
#endif /* defined(__cplusplus) */
    
    struct json_object;
    
#if !defined(__mipci_conf_type_magic)
#define __mipci_conf_type_magic 0x119c143c
#pragma pack(push, 1)
    typedef struct mipci_conf
    {
        struct pack_lenstr  user;           /*  */
        struct pack_lenstr  password;       /*  */
        struct pack_lenstr  password_md5;   /*  */
        struct pack_lenstr  server;         /*  */
        uint32_t            profile_id;     /* profile id,0:1280x720 1:640x360 2:320x180 3:160x90 */
        uint32_t            dis_audio;      /*  */
        uint32_t            dis_vibrate;    /*  */
        uint32_t            buf;            /* 0:0s 1:5s 2:10s 3:15s */
        struct pack_lenstr  version;        /*  */
        struct pack_lenstr  exSrv;          /*  */
        struct pack_lenstr  exSignal_Srv;   /*  */
        uint32_t            ring;           /*  */
        uint32_t            auto_login;     /*  */
        uint32_t            user_online;    /*  */
        struct pack_lenstr  home_url;       /*  */
        struct pack_lenstr  faq_url;        /*  */
        struct pack_lenstr  report_url;     /*  */
        uint32_t            home_set;       /*  */
        uint32_t            faq_set;        /*  */
    }_mipci_conf;
#pragma pack(pop)
#elif (__mipci_conf_type_magic != 0x119c143c)
#error mipci_conf type defined but not match
#endif /* !defined(__mipci_conf_type_magic) */
    
    NSString    *MIPC_GetFileFullPath(NSString *subPath);
    
    struct mipci_conf   *MIPC_ConfigLoad();
    long MIPC_ConfigSave(struct mipci_conf *conf);

    long MIPC_ParseLineParams(struct len_str *text, struct len_str *id_value, struct len_str *password_value, struct len_str *password_md5_value, struct len_str *wifi_value);

    NSString *MIPC_GetLanguageString(char* type, char *name);
    struct json_object *json_get_field(struct json_object *field_array, unsigned long name_len, char *name);
    NSString *json_get_field_string(struct json_object *field_array, unsigned long name_len, char *name);
    long  json_get_field_long(struct json_object *field_array, unsigned long name_len, char *name);
    NSString *MIPC_GetWifiAddress(void);
    NSString *MIPC_GetWifiSSID(NSString **bssid/* [out] */);
    NSString *MIPC_GetConnectedIPCDevID(void);

    NSString *MIPC_BuildEncryptSysInfo(NSString *user, NSString *password);
    
    NSString *MIPC_PostBuildEncryptSysInfo(NSString *user, NSString *password);

    NSString *MIPC_BuildEncryptExceptionInfo(NSString *type, NSString *model,NSString *name,NSString *reason,NSString *call_stack, NSString *user,NSString *password);
    NSString *MIPC_GetEngineKey(void);
    NSMutableDictionary *MIPC_GetApplicationConfigInfo(void);
    NSString *MIPC_SrvFix(NSString *srv);
    struct json_object *MIPC_DataTransformToJson(NSData *data);
    
    unsigned char * getdefaultgateway(in_addr_t * addr);
    
    //-----test-----//
    struct json_object *json_get_old_field(struct json_object *field_array, unsigned long name_len, char *name);
    NSString *json_get_old_field_string(struct json_object *field_array, unsigned long name_len, char *name);
    //-----test-----//
#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#ifndef _NET_ROUTE_H_
#define	_NET_ROUTE_H_
#include <sys/appleapiopts.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/socket.h>

/*
 * These numbers are used by reliable protocols for determining
 * retransmission behavior and are included in the routing structure.
 */
struct rt_metrics {
    u_int32_t	rmx_locks;	/* Kernel leaves these values alone */
    u_int32_t	rmx_mtu;	/* MTU for this path */
    u_int32_t	rmx_hopcount;	/* max hops expected */
    int32_t		rmx_expire;	/* lifetime for route, e.g. redirect */
    u_int32_t	rmx_recvpipe;	/* inbound delay-bandwidth product */
    u_int32_t	rmx_sendpipe;	/* outbound delay-bandwidth product */
    u_int32_t	rmx_ssthresh;	/* outbound gateway buffer limit */
    u_int32_t	rmx_rtt;	/* estimated round trip time */
    u_int32_t	rmx_rttvar;	/* estimated rtt variance */
    u_int32_t	rmx_pksent;	/* packets sent using this route */
    u_int32_t	rmx_filler[4];	/* will be used for T/TCP later */
};

/*
 * rmx_rtt and rmx_rttvar are stored as microseconds;
 */
#define	RTM_RTTUNIT	1000000	/* units for rtt, rttvar, as units per sec */



#define	RTF_UP		0x1		/* route usable */
#define	RTF_GATEWAY	0x2		/* destination is a gateway */
#define	RTF_HOST	0x4		/* host entry (net otherwise) */
#define	RTF_REJECT	0x8		/* host or net unreachable */
#define	RTF_DYNAMIC	0x10		/* created dynamically (by redirect) */
#define	RTF_MODIFIED	0x20		/* modified dynamically (by redirect) */
#define	RTF_DONE	0x40		/* message confirmed */
#define	RTF_DELCLONE	0x80		/* delete cloned route */
#define	RTF_CLONING	0x100		/* generate new routes on use */
#define	RTF_XRESOLVE	0x200		/* external daemon resolves name */
#define	RTF_LLINFO	0x400		/* generated by link layer (e.g. ARP) */
#define	RTF_STATIC	0x800		/* manually added */
#define	RTF_BLACKHOLE	0x1000		/* just discard pkts (during updates) */
#define	RTF_NOIFREF	0x2000		/* not eligible for RTF_IFREF */
#define	RTF_PROTO2	0x4000		/* protocol specific routing flag */
#define	RTF_PROTO1	0x8000		/* protocol specific routing flag */

#define	RTF_PRCLONING	0x10000		/* protocol requires cloning */
#define	RTF_WASCLONED	0x20000		/* route generated through cloning */
#define	RTF_PROTO3	0x40000		/* protocol specific routing flag */
/* 0x80000 unused */
#define	RTF_PINNED	0x100000	/* future use */
#define	RTF_LOCAL	0x200000	/* route represents a local address */
#define	RTF_BROADCAST	0x400000	/* route represents a bcast address */
#define	RTF_MULTICAST	0x800000	/* route represents a mcast address */
#define	RTF_IFSCOPE	0x1000000	/* has valid interface scope */
#define	RTF_CONDEMNED	0x2000000	/* defunct; no longer modifiable */
#define	RTF_IFREF	0x4000000	/* route holds a ref to interface */
#define	RTF_PROXY	0x8000000	/* proxying, no interface scope */
#define	RTF_ROUTER	0x10000000	/* host is a router */
/* 0x20000000 and up unassigned */

#define	RTF_BITS \
"\020\1UP\2GATEWAY\3HOST\4REJECT\5DYNAMIC\6MODIFIED\7DONE" \
"\10DELCLONE\11CLONING\12XRESOLVE\13LLINFO\14STATIC\15BLACKHOLE" \
"\16NOIFREF\17PROTO2\20PROTO1\21PRCLONING\22WASCLONED\23PROTO3" \
"\25PINNED\26LOCAL\27BROADCAST\30MULTICAST\31IFSCOPE\32CONDEMNED" \
"\33IFREF\34PROXY\35ROUTER"

/*
 * Routing statistics.
 */
struct	rtstat {
    short	rts_badredirect;	/* bogus redirect calls */
    short	rts_dynamic;		/* routes created by redirects */
    short	rts_newgateway;		/* routes modified by redirects */
    short	rts_unreach;		/* lookups which failed */
    short	rts_wildcard;		/* lookups satisfied by a wildcard */
};

/*
 * Structures for routing messages.
 */
struct rt_msghdr {
    u_short	rtm_msglen;	/* to skip over non-understood messages */
    u_char	rtm_version;	/* future binary compatibility */
    u_char	rtm_type;	/* message type */
    u_short	rtm_index;	/* index for associated ifp */
    int	rtm_flags;	/* flags, incl. kern & message, e.g. DONE */
    int	rtm_addrs;	/* bitmask identifying sockaddrs in msg */
    pid_t	rtm_pid;	/* identify sender */
    int	rtm_seq;	/* for sender to identify action */
    int	rtm_errno;	/* why failed */
    int	rtm_use;	/* from rtentry */
    u_int32_t rtm_inits;	/* which metrics we are initializing */
    struct rt_metrics rtm_rmx; /* metrics themselves */
};

struct rt_msghdr2 {
    u_short	rtm_msglen;	/* to skip over non-understood messages */
    u_char	rtm_version;	/* future binary compatibility */
    u_char	rtm_type;	/* message type */
    u_short	rtm_index;	/* index for associated ifp */
    int	rtm_flags;	/* flags, incl. kern & message, e.g. DONE */
    int	rtm_addrs;	/* bitmask identifying sockaddrs in msg */
    int32_t	rtm_refcnt;	/* reference count */
    int	rtm_parentflags; /* flags of the parent route */
    int	rtm_reserved;	/* reserved field set to 0 */
    int	rtm_use;	/* from rtentry */
    u_int32_t rtm_inits;	/* which metrics we are initializing */
    struct rt_metrics rtm_rmx; /* metrics themselves */
};


#define	RTM_VERSION	5	/* Up the ante and ignore older versions */

/*
 * Message types.
 */
#define	RTM_ADD		0x1	/* Add Route */
#define	RTM_DELETE	0x2	/* Delete Route */
#define	RTM_CHANGE	0x3	/* Change Metrics or flags */
#define	RTM_GET		0x4	/* Report Metrics */
#define	RTM_LOSING	0x5	/* Kernel Suspects Partitioning */
#define	RTM_REDIRECT	0x6	/* Told to use different route */
#define	RTM_MISS	0x7	/* Lookup failed on this address */
#define	RTM_LOCK	0x8	/* fix specified metrics */
#define	RTM_OLDADD	0x9	/* caused by SIOCADDRT */
#define	RTM_OLDDEL	0xa	/* caused by SIOCDELRT */
#define	RTM_RESOLVE	0xb	/* req to resolve dst to LL addr */
#define	RTM_NEWADDR	0xc	/* address being added to iface */
#define	RTM_DELADDR	0xd	/* address being removed from iface */
#define	RTM_IFINFO	0xe	/* iface going up/down etc. */
#define	RTM_NEWMADDR	0xf	/* mcast group membership being added to if */
#define	RTM_DELMADDR	0x10	/* mcast group membership being deleted */
#define	RTM_IFINFO2	0x12	/* */
#define	RTM_NEWMADDR2	0x13	/* */
#define	RTM_GET2	0x14	/* */

/*
 * Bitmask values for rtm_inits and rmx_locks.
 */
#define	RTV_MTU		0x1	/* init or lock _mtu */
#define	RTV_HOPCOUNT	0x2	/* init or lock _hopcount */
#define	RTV_EXPIRE	0x4	/* init or lock _expire */
#define	RTV_RPIPE	0x8	/* init or lock _recvpipe */
#define	RTV_SPIPE	0x10	/* init or lock _sendpipe */
#define	RTV_SSTHRESH	0x20	/* init or lock _ssthresh */
#define	RTV_RTT		0x40	/* init or lock _rtt */
#define	RTV_RTTVAR	0x80	/* init or lock _rttvar */

/*
 * Bitmask values for rtm_addrs.
 */
#define	RTA_DST		0x1	/* destination sockaddr present */
#define	RTA_GATEWAY	0x2	/* gateway sockaddr present */
#define	RTA_NETMASK	0x4	/* netmask sockaddr present */
#define	RTA_GENMASK	0x8	/* cloning mask sockaddr present */
#define	RTA_IFP		0x10	/* interface name sockaddr present */
#define	RTA_IFA		0x20	/* interface addr sockaddr present */
#define	RTA_AUTHOR	0x40	/* sockaddr for author of redirect */
#define	RTA_BRD		0x80	/* for NEWADDR, broadcast or p-p dest addr */

/*
 * Index offsets for sockaddr array for alternate internal encoding.
 */
#define	RTAX_DST	0	/* destination sockaddr present */
#define	RTAX_GATEWAY	1	/* gateway sockaddr present */
#define	RTAX_NETMASK	2	/* netmask sockaddr present */
#define	RTAX_GENMASK	3	/* cloning mask sockaddr present */
#define	RTAX_IFP	4	/* interface name sockaddr present */
#define	RTAX_IFA	5	/* interface addr sockaddr present */
#define	RTAX_AUTHOR	6	/* sockaddr for author of redirect */
#define	RTAX_BRD	7	/* for NEWADDR, broadcast or p-p dest addr */
#define	RTAX_MAX	8	/* size of array to allocate */

struct rt_addrinfo {
    int	rti_addrs;
    struct	sockaddr *rti_info[RTAX_MAX];
};

//#endif /* _NET_ROUTE_H_ */
//
//#ifndef MSTEnterprise_getgateway_h
//#define MSTEnterprise_getgateway_h
//#include <TargetConditionals.h>
//
//
//// 模拟器调试里可以编译通过并执行，而选真机调试时却在编译中显示该文件找不到 net/route.h
//
//#if  TARGET_IPHONE_SIMULATOR
//#include <net/route.h>
//#include "MIPCUtils.h"
//#elif TARGET_OS_IPHONE
//#include "MIPCUtils.h"
//#endif
//
//unsigned char * getdefaultgateway(in_addr_t * addr);
//
#endif

