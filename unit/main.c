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

#include    <stdio.h>
#include    <stdlib.h>
#include    <assert.h>
#include    <time.h>
#include    <unistd.h>

#include    "microlist.h"

static int  cb_sort(void *it1, void *it2)
{
  int       a = *((int *)it1);
  int       b = *((int *)it2);
  return (a < b);
}

static void test_init(void)
{
  microlist *list;

  puts("Running init test...");
  list = microlist_init();
  assert(list != NULL && list->size == 0);
  assert(list->head == NULL && list->tail == NULL);
  microlist_free(list);
}

static void test_insert(void)
{
  microlist *list;
  microitem *item;
  microitem *item2;
  microitem *item3;
  microitem *item4;
  unsigned int ret;

  puts("Running insert test");
  list = microlist_init();
  item = microlist_append(list, NULL);
  assert(item->prev == NULL && item->next == NULL && list->size == 1);
  item2 = microlist_append(list, NULL);
  assert(item2->prev == item && item2->next == NULL && list->size == 2);
  item3 = microlist_insert_after(list, list->head, NULL);
  assert(item3->next == item2 && item3->prev == item && list->size == 3);
  item4 = microlist_prepend(list, NULL);
  assert(list->head == item4 && item4->next == item && item4->prev == NULL && list->size == 4);
  // item4 -> item -> item3 -> item2
  puts("Running delete test");
  ret = microitem_remove(item4);
  assert(ret == 3 && list->head == item && list->tail == item2);
  // item -> item3 -> item2
  ret = microitem_remove(item3);
  assert(ret == 2 && item->next == item2 && item2->prev == item);
  // item -> item2
  ret = microitem_remove(item);
  assert(ret == 1 && list->head == item2 && list->tail == item2 && item2->prev == NULL && item2->next == NULL);
  ret = microitem_remove(item2);
  assert(ret == 0 && list->size == 0 && list->head == NULL && list->tail == NULL);
  microlist_free(list);
}

static void test_insert_sort()
{
  microlist *list;
  int       *tmp;
  int       min = 0;
  int       value;
  int       i = 0;
  microitem *current;

  srand(time(NULL));
  list = microlist_init();
  for (i = 0; i != 3000; ++i)
  {
    tmp = malloc(sizeof(*tmp));
    assert(tmp != NULL);
    *tmp = rand();
    microlist_insert_sort(list, tmp, cb_sort);
  }
  current = list->head;
  while (current)
  {
    value = *((int *)current->data);
    assert(value >= min);
    min = value;
    free(current->data);
    current = current->next;
  }
  microlist_free(list);
  write(STDOUT_FILENO, "..", 2);
}

int         main(void)
{
  int       i = 0;
  puts("Running unit tests...");
  test_init();
  test_insert();
  puts("Running 100 sorted insertion test w/ random values");
  for (i = 0; i != 100; ++i)
  {
    test_insert_sort();
  }
  puts("");
  puts("All unit tests passed, great!");
  return (EXIT_SUCCESS);
}
