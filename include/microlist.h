// Copyright 2011 Adrien Siami

//   Licensed under the Apache License, Version 2.0 (the "License");
//   you may not use this file except in compliance with the License.
//   You may obtain a copy of the License at

//       http://www.apache.org/licenses/LICENSE-2.0

//   Unless required by applicable law or agreed to in writing, software
//   distributed under the License is distributed on an "AS IS" BASIS,
//   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//   See the License for the specific language governing permissions and
//   limitations under the License.

#ifndef      __MICROLIST__
# define     __MICROLIST__

/**
 * \file microlist.h
 */

struct               s_microlist; // Forward declaration

typedef struct       s_microitem
{
  struct s_microlist *list;
  struct s_microitem *next;
  struct s_microitem *prev;
  void               *data;
}                    microitem;

typedef struct s_microlist
{
  unsigned int size;
  microitem    *head;
  microitem    *tail;
}              microlist;

/**
 * \brief Create a microitem
 * \param list Pointer to the list where the item will be stored
 * \param data Data to be stored
 * \return The microitem or NULL if malloc (3) fails
 */

microitem   *microitem_create(microlist *list, void *data);

/**
 * \brief Inits a micro list
 * \return Pointer to the microlist
 */

microlist   *microlist_init(void);

/**
 * \brief Inserts an element after a given element
 * \param list Pointer to the list
 * \param item Item after which insert the element
 * \param data Pointer on the data to be stored in the list
 * \return Pointer to the newly created microitem
 */

microitem   *microlist_insert_after(microlist *list, microitem *item, void *data);

/**
 * \brief Inserts an element at the end of the list
 * \param list Pointer to the list
 * \param data Pointer on the data to be stored in the list
 * \return Pointer to the newly created microitem
 */

microitem   *microlist_append(microlist *list, void *data);


/**
 * \brief Inserts an element before a given element
 * \param list Pointer to the list
 * \param item Item before which insert the element
 * \param data Pointer on the data to be stored in the list
 * \return Pointer to the newly created microitem
 */

microitem   *microlist_insert_before(microlist *list, microitem *item, void *data);

/**
 * \brief Inserts an element at the beginning of the list
 * \param list Pointer to the list
 * \param data Pointer on the data to be stored in the list
 * \return Pointer to the newly created microitem
 */

microitem   *microlist_prepend(microlist *list, void *data);

/**
 * \brief Removes an item from the list and frees the pointer
 * \param item the item to be removed, data is NOT freed
 * \return The new size of the list
 */

 unsigned int microitem_remove(microitem *item);

 /**
  * \brief Inserts an item in a sorted list
  * \param list The already sorted or empty list
  * \param data The data to insert
  * \param cb The callback function for comparison between to elements
  * \return The newly created item, the list is still sorted
  */

 microitem   *microlist_insert_sort(microlist *list, void *data, int (*cb)(void *, void *));

#endif      /* __MICROLIST__ */
