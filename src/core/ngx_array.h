
/*
 * Copyright (C) Igor Sysoev
 * Copyright (C) Nginx, Inc.
 */


#ifndef _NGX_ARRAY_H_INCLUDED_
#define _NGX_ARRAY_H_INCLUDED_


#include <ngx_config.h>
#include <ngx_core.h>


// struct ngx_array_t
// nginx 数组结构 {{{
typedef struct {
    void        *elts;		// 数组起始位置
    ngx_uint_t   nelts;		// 当前数组中元素个数
    size_t       size;		// 单个元素大小
    ngx_uint_t   nalloc;	// 数组容量
    ngx_pool_t  *pool;		// 内存池地址
} ngx_array_t; // }}}


ngx_array_t *ngx_array_create(ngx_pool_t *p, ngx_uint_t n, size_t size);
void ngx_array_destroy(ngx_array_t *a);
void *ngx_array_push(ngx_array_t *a);
void *ngx_array_push_n(ngx_array_t *a, ngx_uint_t n);

<<<<<<< HEAD

// static ngx_inline ngx_int_t
// ngx_array_init(ngx_array_t *array, ngx_pool_t *pool,
//     ngx_uint_t n, size_t size)
// 数组结构初始化 {{{
=======
// static ngx_inline ngx_int_t ngx_array_init(
//     ngx_array_t *array, ngx_pool_t *pool, ngx_uint_t n, size_t size
// )
// 数组结构初始化
>>>>>>> origin/master
static ngx_inline ngx_int_t
ngx_array_init(ngx_array_t *array, ngx_pool_t *pool, ngx_uint_t n, size_t size)
{
    /*
     * set "array->nelts" before "array->elts", otherwise MSVC thinks
     * that "array->nelts" may be used without having been initialized
     */

    array->nelts = 0;
    array->size = size;
    array->nalloc = n;
    array->pool = pool;

<<<<<<< HEAD
	// 为数组分配初始空间
=======
	// 开辟空间
>>>>>>> origin/master
    array->elts = ngx_palloc(pool, n * size);
    if (array->elts == NULL) {
        return NGX_ERROR;
    }

    return NGX_OK;
} // }}}


#endif /* _NGX_ARRAY_H_INCLUDED_ */
