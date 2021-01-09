#ifndef _BG_ALL_P_H_
#define _BG_ALL_P_H_

struct bg_header
{
    unsigned int RESERVED;
    struct room_data_table *roomdatatable;
    struct portal_data_table *portaldatatable;
    struct global_visibility_commands *globalviscommands;
    unsigned int PADDING;
};

struct room_data_table_entry
{
    void *pointtablebinary;
    void *primappingbinary;
    void *secmappingbinary;
    float x;
    float y;
    float z;
};

/* 2 */
struct portal_data_table_entry
{
    void *offset_portal_address;
    char connected_room1;
    char connected_room2;
    unsigned short control_bytes;
};

struct xyzpoint
{
    float x;
    float y;
    float z;
};

/* 3 */
struct portal_3_point
{
    char numpoints;
    char padding1;
    char padding2;
    char padding3;
    struct xyzpoint points[3];
};

struct portal_4_point
{
    char numpoints;
    char padding1;
    char padding2;
    char padding3;
    struct xyzpoint points[4];
};

struct portal_5_point
{
    char numpoints;
    char padding1;
    char padding2;
    char padding3;
    struct xyzpoint points[5];
};

struct portal_6_point
{
    char numpoints;
    char padding1;
    char padding2;
    char padding3;
    struct xyzpoint points[6];
};

extern struct room_data_table_entry room_data_table[];
extern struct portal_data_table_entry portal_data_table[];
extern unsigned int global_visibility_commands[];

#endif
