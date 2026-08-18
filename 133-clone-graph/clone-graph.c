struct Node* dfs(struct Node* node, struct Node* visited[]);

struct Node* cloneGraph(struct Node* node) {
    if (node == NULL)
        return NULL;

    struct Node* visited[101] = {NULL};

    return dfs(node, visited);
}

struct Node* dfs(struct Node* node, struct Node* visited[]) {
    if (node == NULL)
        return NULL;

    if (visited[node->val] != NULL)
        return visited[node->val];

    struct Node* clone = malloc(sizeof(struct Node));

    clone->val = node->val;
    clone->numNeighbors = node->numNeighbors;

    visited[node->val] = clone;

    if (node->numNeighbors > 0) {
        clone->neighbors =
            malloc(node->numNeighbors * sizeof(struct Node*));

        for (int i = 0; i < node->numNeighbors; i++) {
            clone->neighbors[i] =
                dfs(node->neighbors[i], visited);
        }
    } else {
        clone->neighbors = NULL;
    }

    return clone;
}