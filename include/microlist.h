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

#endif      /* __MICROLIST__ */