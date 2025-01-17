#include "routes.h"
#include "io.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const rmux_pattern rmux_patterns[70+4] = {
  {  1,  1,   1,     0x0,   0,   0,    0 },
  {  1,  2,   2,     0x0,   0,   1,    1 },
  {  4,  4,   5,     0x0,   1,   3,    3 },
  {  4,  4,   5,     0x0,   5,   3,    3 },
  {  4,  4,   5,     0x0,   9,   3,    3 },
  {  4,  4,   5,     0x0,  13,   3,    3 },
  {  5,  5,   9,    0x10,  17,   7,    8 },
  {  6,  6,   9,    0x00,  22,  12,   17 },
  {  6,  6,   9,    0x00,  28,  12,   17 },
  {  6,  6,   9,    0x00,  34,  12,   17 },
  {  6,  6,   9,    0x00,  40,  12,   17 },
  {  6,  6,   9,    0x00,  46,  12,   17 },
  {  7, 12,  29,    0x00,  52,  18,   26 },
  {  7, 12,  32,    0x00,  59,  30,   55 },
  {  7, 12,  32,    0x00,  66,  30,   55 },
  {  7, 12,  32,    0x00,  73,  42,   87 },
  {  8, 18,  51,   0x000,  80,  54,  119 },
  {  9,  9,  11,   0x000,  88,  72,  170 },
  {  9, 18,  73,   0x000,  97,  81,  181 },
  {  9, 18,  73,   0x000, 106,  81,  181 },
  {  9, 17,  36,   0x000, 115,  99,  254 },
  {  9, 17,  36,   0x000, 124,  99,  254 },
  {  9, 17,  36,   0x000, 133, 116,  290 },
  {  9, 17,  36,   0x000, 142, 116,  290 },
  {  9, 17,  36,   0x000, 151, 116,  290 },
  {  9, 17,  36,   0x000, 160, 116,  290 },
  {  9, 18,  73,   0x000, 169,  81,  181 },
  {  9,  9,  11,   0x000, 178,  72,  170 },
  { 10, 22,  51,   0x011, 187, 133,  326 },
  { 10, 10,  11,   0x000, 197, 155,  377 },
  { 11, 22,  91,   0x000, 207, 165,  388 },
  { 11, 22,  69,   0x000, 218, 187,  479 },
  { 11, 22,  91,   0x000, 229, 165,  388 },
  { 11, 25, 103,   0x220, 240, 209,  548 },
  { 11, 23,  44,   0x000, 251, 234,  651 },
  { 11, 23,  44,   0x000, 262, 234,  651 },
  { 11, 23,  44,   0x000, 273, 257,  695 },
  { 11, 23,  44,   0x000, 284, 257,  695 },
  { 11, 23,  44,   0x000, 295, 234,  651 },
  { 11, 23,  44,   0x000, 306, 234,  651 },
  { 12, 30, 109,   0x021, 317, 280,  739 },
  { 13, 30,  91,  0x0000, 329, 310,  848 },
  { 13, 30,  91,  0x0000, 342, 310,  848 },
  { 13, 30,  91,  0x0000, 355, 310,  848 },
  { 13, 30,  91,  0x0000, 368, 310,  848 },
  { 13, 30,  91,  0x0000, 381, 310,  848 },
  { 13, 30,  91,  0x0000, 394, 310,  848 },
  { 15, 36, 175,  0x0000, 407, 340,  939 },
  { 15, 36, 175,  0x0000, 422, 340,  939 },
  { 15, 36, 175,  0x0000, 437, 340,  939 },
  { 15, 36, 175,  0x0000, 452, 340,  939 },
  { 15, 36, 175,  0x0000, 467, 340,  939 },
  { 15, 36, 175,  0x0000, 482, 340,  939 },
  { 15, 36,  52,  0x0000, 497, 376, 1114 },
  { 15, 36,  52,  0x0000, 512, 376, 1114 },
  { 15, 36, 175,  0x0000, 527, 340,  939 },
  { 15, 36, 175,  0x0000, 542, 340,  939 },
  { 15, 36, 175,  0x0000, 557, 340,  939 },
  { 17, 40,  76, 0x00000, 572, 412, 1166 },
  { 17, 40,  76, 0x00000, 589, 412, 1166 },
  { 17, 40,  76, 0x00000, 606, 412, 1166 },
  { 17, 40,  76, 0x00000, 623, 412, 1166 },
  { 17, 42, 175, 0x00000, 640, 452, 1242 },
  { 17, 42, 175, 0x00000, 657, 452, 1242 },
  { 17, 40, 119, 0x00000, 674, 494, 1417 },
  { 17, 40, 119, 0x00000, 691, 494, 1417 },
  { 18, 44,  76, 0x00000, 708, 534, 1536 },
  { 18, 44,  76, 0x00000, 726, 534, 1536 },
  { 18, 44,  76, 0x00000, 744, 578, 1612 },
  { 18, 44,  76, 0x00000, 762, 578, 1612 },
  {  5,  5,   9,    0x01,  17,   7,    8 },
  {  5,  5,   9,    0x02,  17,   7,    8 },
  {  5,  5,   9,    0x04,  17,   7,    8 },
  {  5,  5,   9,    0x08,  17,   7,    8 },
};

RoutesParser::RoutesParser(const NodesReader &_nr, const std::vector<uint8_t> &data, uint32_t _width) : nr(_nr), width(_width)
{
  p = data.data();
  e = data.data() + data.size();
  next();
}

void RoutesParser::error(const uint8_t *st, const char *err) const
{
  if(err)
    fprintf(stderr, "%s\n", err);
  const uint8_t *en = st;
  while(*en != '\n' && *en != '\r')
    en++;
  std::string line(st, en);
  fprintf(stderr, "line: %s\n", line.c_str());
  exit(1);
};

void RoutesParser::next()
{
  pattern = 0;
  fw_pos = 0;
  std::fill(sources.begin(), sources.end(), rnode_coords());

  if(p == e) {
    rn = rnode_coords();
    return;
  }

  const uint8_t *st = p;

  rn = nr.lookup_r(p);
  if(!rn)
    error(st);
  if(*p++ != ' ')
    error(st, "Space expected after destination node");

  if(*p == '-') {
    p++;
    skipsp(p);
    pattern = 0xfe;
    fw_pos = 0;

  } else {
    int pat = lookup_int(p);
    if(pat == -1 || (*p != ':' && *p != '.'))
      error(st, "Incorrect pattern number");
    if(*p == '.') {
      if(pat != 6)
	error(st, "Only pattern 6 has options");
      p++;
      int patopt = lookup_int(p);
      if(pat == -1 || *p != ':')
	error(st, "Incorrect pattern option");
      pat = 70 + patopt;
    }
    p++;
    pattern = pat;
    
    int pat_x = lookup_int(p);
    if(pat_x == -1 || *p++ != '_')
      error(st, "Incorrect pattern x position");
    
    int pat_y = lookup_int(p);
    if(pat_y == -1 || (*p != ' ' && *p != '\r' && *p != '\n'))
      error(st, "Incorrect pattern y position");
    skipsp(p);
    
    fw_pos = pat_x + pat_y * width;
  }

  while(*p != '\r' && *p != '\n') {
    int slot = lookup_int(p);
    if(slot == -1 || slot >= 44 || *p++ != ':')
      error(st, "Incorrect slot number");
    rnode_coords srn = nr.lookup_r(p);
    if(!srn)
      error(st);
    sources[slot] = srn;
    if(*p == ' ')
      p++;
  }

  if(*p == '\r')
    p++;
  if(*p++ != '\n')
    error(st, "Missing \\n at end of line");
}

