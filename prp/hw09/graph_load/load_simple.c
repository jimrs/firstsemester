#include <stdio.h>

#include "graph_utils.h"
#include "load_simple.h"

int load_graph_simple(const char *fname, graph_t *g) 
{
   int c = 0;
   int exit = 0;
   FILE *f = fopen(fname, "r");
   while (!feof(f) && !exit) {
      if (g->num_edges == g->capacity) {
         enlarge_graph(g);
      }
      edge_t *e = g->edges + g->num_edges;
      while (!feof(f) && g->num_edges < g->capacity) {
         int r = fscanf(f, "%d %d %d\n", &(e->from), &(e->to), &(e->cost));
         if (r == 3) {
            g->num_edges += 1;
            c += 1;
            e += 1;
         } else {
            exit = 1;
            break;
         }
      }
   }
   fclose(f);
   return c;
}
