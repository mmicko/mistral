#include "nodes.h"
#include "io.h"

#include <stdio.h>

const char *const rnode_type_names[] = {
#define P(x) #x
#include "cv-rnodetypes.ipp"
#undef P
  nullptr
};

const char *const block_type_names[] = {
#define P(x) #x
#include "cv-blocktypes.ipp"
#undef P
  nullptr
};

const char *const port_type_names[] = {
#define P(x) #x
#include <cv-porttypes.ipp>
#undef P
  nullptr
};


NodesReader::NodesReader() : rnames(rnode_type_names), bnames(block_type_names), pnames(port_type_names)
{
}

rnode_coords NodesReader::lookup_r(const uint8_t *&p) const
{
  int t = rnames.lookup(p);
  if(t == -1) {
    fprintf(stderr, "Rnode type unknown\n");
    return rnode_coords();
  }
  if(*p++ != '.') {
    fprintf(stderr, "Missing '.' after rnode type\n");
    return rnode_coords();
  }
  int x = lookup_int(p);
  if(x == -1) {
    fprintf(stderr, "Missing x\n");
    return rnode_coords();
  }
  if(*p++ != '.') {
    fprintf(stderr, "Missing '.' after rnode x\n");
    return rnode_coords();
  }
  int y = lookup_int(p);
  if(y == -1) {
    fprintf(stderr, "Missing y\n");
    return rnode_coords();
  }
  if(*p++ != '.') {
    fprintf(stderr, "Missing '.' after rnode y\n");
    return rnode_coords();
  }
  int z = lookup_int(p);
  if(z == -1) {
    fprintf(stderr, "Missing z\n");
    return rnode_coords();
  }
  return rnode_coords(rnode_type_t(t), x, y, z);
}

pnode_coords NodesReader::lookup_p(const uint8_t *&p) const
{
  int b = bnames.lookup(p);
  if(b == -1) {
    fprintf(stderr, "Block type unknown\n");
    return pnode_coords();
  }
  if(*p++ != '.') {
    fprintf(stderr, "Missing '.' after rnode type\n");
    return pnode_coords();
  }
  int x = lookup_int(p);
  if(x == -1) {
    fprintf(stderr, "Missing x\n");
    return pnode_coords();
  }
  if(*p++ != '.') {
    fprintf(stderr, "Missing '.' after rnode x\n");
    return pnode_coords();
  }
  int y = lookup_int(p);
  if(y == -1) {
    fprintf(stderr, "Missing y\n");
    return pnode_coords();
  }
  int bi = -1;
  if(*p == '.') {
    p++;
    bi = lookup_int(p);
    if(bi == -1) {
      fprintf(stderr, "Missing instance number\n");
      return pnode_coords();
    }
  }

  int t = PNONE, pi = -1;

  if(*p == ':') {
    p++;
    t = pnames.lookup(p);
    if(t == -1) {
      fprintf(stderr, "Port type unknown\n");
      return pnode_coords();
    }
    if(*p == '.') {
      p++;
      pi = lookup_int(p);
      if(pi == -1) {
	fprintf(stderr, "Missing port index number\n");
	return pnode_coords();
      }
    }
  }

  return pnode_coords(block_type_t(b), x, y, port_type_t(t), bi, pi);
}

block_type_t NodesReader::lookup_block(const uint8_t *&p) const
{
  int t = bnames.lookup(p);
  if(t == -1) {
    fprintf(stderr, "Block type unknown\n");
    return BNONE;
  }
  return block_type_t(t);
}

port_type_t NodesReader::lookup_port(const uint8_t *&p) const
{
  int t = pnames.lookup(p);
  if(t == -1) {
    fprintf(stderr, "Port type unknown\n");
    return PNONE;
  }
  return port_type_t(t);
}

