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

#include    <stdlib.h>
#include    <assert.h>
#include    "microlist.h"

static void microitem_insert_empty(microlist *list, microitem *elem)
{
  assert(list->tail == NULL && list->head == NULL && list->size == 0);
  elem->next = NULL;
  elem->prev = NULL;
  list->head = elem;
  list->tail = elem;
}

static void microitem_insert_after(microlist *list, microitem *target, microitem *elem)
{
  assert(list != NULL);
  if (target == NULL) // The list is empty
  {
    microitem_insert_empty(list, elem);
  }
  else // Standard insert
  {
    elem->next = target->next;
    if (target->next)
      target->next->prev = elem;
    else // The target is the tail, update it
      list->tail = elem;
    elem->prev = target;
    if (elem->prev)
      elem->prev->next = elem;
    target->next = elem;
  }
  ++list->size;
}

static void microitem_insert_before(microlist *list, microitem *target, microitem *elem)
{
  assert(list != NULL);
  if (target == NULL) // The list is empty
  {
    microitem_insert_empty(list, elem);
  }
  else // Standard insert
  {
    elem->prev = target->prev;
    if (target->prev)
      target->prev->next = elem;
    else // The target is the head, update it
      list->head = elem;
    elem->next = target;
    if (elem->next)
      elem->next->prev = elem;
    target->prev = elem;
  }
  ++list->size;
}

microitem   *microlist_insert_after(microlist *list, microitem *target, void *data)
{
  microitem *item;

  assert(list != NULL);
  item = malloc(sizeof(*item));
  if (!item)
    return (NULL);
  item->data = data;
  microitem_insert_after(list, target, item);
  return (item);
}

microitem   *microlist_insert_before(microlist *list, microitem *target, void *data)
{
  microitem *item;

  assert(list != NULL);
  item = malloc(sizeof(*item));
  if (!item)
    return (NULL);
  item->data = data;
  microitem_insert_before(list, target, item);
  return (item);
}

microitem   *microlist_append(microlist *list, void *data)
{
  return (microlist_insert_after(list, list->tail, data));
}

microitem   *microlist_prepend(microlist *list, void *data)
{
  return (microlist_insert_before(list, list->head, data));
}

