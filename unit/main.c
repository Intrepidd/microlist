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

#include    "microlist.h"

void        test_init(void)
{
  microlist *list;

  puts("Running init test...");
  list = microlist_init();
  assert(list != NULL && list->size == 0);
  assert(list->head == NULL && list->tail == NULL);
}

void        test_insert(void)
{
  microlist *list;
  microitem *item;
  microitem *item2;

  puts("Running insert test");
  list = microlist_init();
  item = microlist_append(list, NULL);
  assert(item->prev == NULL && item->next == NULL && list->size == 1);
  item2 = microlist_append(list, NULL);
  assert(item2->prev == item && item2->next == NULL && list->size == 2);
}

int         main(void)
{
  puts("Running unit tests...");
  test_init();
  test_insert();
  puts("All unit tests passed, great!");
  return (EXIT_SUCCESS);
}
