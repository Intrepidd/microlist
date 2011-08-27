
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

microitem   *microlist_insert_sort(microlist *list, void *data, int (*cb)(void *, void *))
{
  microitem *current;

  assert(data != NULL && list != NULL && cb != NULL);
  current = list->head;
  while (current)
  {
    if (cb(data, current->data)) // We can insert
      return (microlist_insert_before(list, current, data));
    current = current->next;
  }
  // No good element was found, that means our element should be the last one
  return (microlist_append(list, data));
}

