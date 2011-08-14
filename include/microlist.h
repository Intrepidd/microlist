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

typedef struct       s_microitem
{
  struct s_microitem *next;
  struct s_microitem *prev;
  void               *data;
}                    microitem;

typedef struct
{
  unsigned int size;
  microitem    *head;
  microitem    *tail;
}              microlist;

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

#endif      /* __MICROLIST__ */