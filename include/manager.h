//
// Created by Maxwell Babey on 10/30/22.
//

#ifndef MEMORY_MANAGER_MANAGER_H
#define MEMORY_MANAGER_MANAGER_H

#include <stddef.h>

/**
 * struct memory_manager
 * <p>
 * A memory manager. Stores a linked list of memory addresses. Contains
 * functions to add, free, or free all memory addresses.
 * </p>
 */
struct memory_manager
{
    struct memory_address *head;
    
    void *(*mm_add)(struct memory_manager *, void *);
    
    int (*mm_free)(struct memory_manager *, void *);
    
    int (*mm_free_all)(struct memory_manager *);
};

/**
 * init_mem_manager
 * <p>
 * Create and initialize a memory manager.
 * </p>
 * @return a memory manager
 */
struct memory_manager *init_mem_manager(void);

/**
 * free_mem_manager
 * <p>
 * Free all memory in a memory manager, then free the memory manager itself.
 * </p>
 * @param mem_manager the memory manager to be freed
 * @return 0 on success, -1 if the memory manager does not exist
 */
int free_mem_manager(struct memory_manager *mem_manager);

/**
 * mm_malloc
 * <p>
 * Call malloc to allocate memory to a pointer. Add the pointer to a
 * memory manager if provided. If no mem_manager is NULL, only malloc
 * will be called.
 * </p>
 * @param size the number of bytes of memory to allocate
 * @param mem_manager the memory manager to which to add the new memory
 * @param file the file in which memory is allocated
 * @param func the function in which memory is allocated
 * @param line the line on which memory is allocated
 * @return a pointer to the newly allocated memory
 */
void *mm_malloc(size_t size, struct memory_manager *mem_manager,
                const char *file, const char *func, size_t line);

/**
 * mm_calloc
 * <p>
 * Call calloc to allocate memory to a pointer. Add the pointer to a
 * memory manager if provided. If no mem_manager is NULL, only calloc
 * will be called.
 * </p>
 * @param count the units of memory to allocate
 * @param size the the size of the units of memory
 * @param mem_manager the memory manager to which to add the new memory
 * @param file the file in which memory is allocated
 * @param func the function in which memory is allocated
 * @param line the line on which memory is allocated
 * @return a pointer to the newly allocated memory
 */
void *mm_calloc(size_t count, size_t size, struct memory_manager *mem_manager,
                const char *file, const char *func, size_t line);

/**
 * mm_realloc
 * <p>
 * Call realloc to reallocate memory to a pointer. Update the pointer in the
 * memory manager if provided. If no mem_manager is NULL, only realloc
 * will be called.
 * </p>
 * @param ptr the pointer for which to reallocate memory
 * @param size the new size of the memory
 * @param mem_manager the memory manager to which to add the new memory
 * @param file the file in which memory is allocated
 * @param func the function in which memory is allocated
 * @param line the line on which memory is allocated
 * @return a pointer to the newly allocated memory
 */
void *mm_realloc(void *ptr, size_t size, struct memory_manager *mem_manager,
                 const char *file, const char *func, size_t line);

/**
 * Mmm_malloc
 * <p>
 * Macro mm_malloc that automatically adds file, func, and line parameters.
 * </p>
 */
#define Mmm_malloc(size, mm) \
    mm_malloc(size, mm, __FILE__, __func__, __LINE__)

/**
 * Mmm_malloc
 * <p>
 * Macro mm_calloc that automatically adds file, func, and line parameters.
 * </p>
 */
#define Mmm_calloc(count, size, mm) \
    mm_calloc(count, size, mm, __FILE__, __func__, __LINE__)

/**
 * Mmm_malloc
 * <p>
 * Macro mm_realloc that automatically adds file, func, and line parameters.
 * </p>
 */
#define Mmm_realloc(ptr, size, mm) \
    mm_realloc(ptr, size, mm, __FILE__, __func__, __LINE__)

#endif //MEMORY_MANAGER_MANAGER_H
