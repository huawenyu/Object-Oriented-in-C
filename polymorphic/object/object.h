#ifndef __OBJECT_H__
#define __OBJECT_H__

#include <assert.h> /* assert */
#include <stddef.h> /* offset */
#include <stdint.h> /* uintptr_t */

/**
 * container_of - get the struct for this entry
 * @ptr:	the &struct list_head pointer.
 * @type:	the type of the struct this is embedded in.
 * @member:	the name of the list_struct within the struct.
 */
#define container_of(ptr, type, member) \
    ((type *)((char *)(ptr)-(unsigned long)(&((type *)0)->member)))

#define __CLASS_STRINGIFY(x) #x
#define __CLASS_TOSTRING(x) __CLASS_STRINGIFY(x)
#define __CLASS_WHERE __FILE__ ":" __CLASS_TOSTRING(__LINE__)

//#pragma message (super_ops)
//#pragma message ((void*)(&(super_ops)->this_sz))
//
#define OBJ_NEW(this, super_ops, ops) \
({ \
    typedef void (*pf) (void); \
    pf *src, *dst; \
    size_t sz = sizeof(*(super_ops)); \
                                      \
    _Static_assert(((void*)(super_ops) == (void*)(&(super_ops)->this_sz)), __CLASS_WHERE "::[" #super_ops ":" #ops "] please add the member `uintptr_t this_sz;` at begin."); \
    if (ops) { \
        assert((uintptr_t)((ops)->dtor) && __CLASS_WHERE "::[" #super_ops ":" #ops "] please implement dtor()."); \
        for (src = (pf*)(&(super_ops)->this_sz), dst = (pf*)(&(ops)->this_sz); \
             (void *)src < (void *)(super_ops) + sz; \
             src++, dst++) { \
            if (*dst == NULL) \
                *dst = *src; \
        } \
    } \
    else \
        ops = super_ops; \
                         \
    this = malloc(ops->this_sz); \
    if (this) \
        this->ops = ops; \
    this; \
}) \

#endif
