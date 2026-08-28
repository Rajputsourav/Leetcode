typedef struct {
    struct TreeNode* stack[100000];
    int top;
} BSTIterator;

void pushLeft(BSTIterator* obj, struct TreeNode* root) {
    while (root != NULL) {
        obj->stack[++obj->top] = root;
        root = root->left;
    }
}

BSTIterator* bSTIteratorCreate(struct TreeNode* root) {
    BSTIterator* obj = (BSTIterator*)malloc(sizeof(BSTIterator));

    obj->top = -1;
    pushLeft(obj, root);

    return obj;
}

int bSTIteratorNext(BSTIterator* obj) {
    struct TreeNode* node = obj->stack[obj->top--];

    if (node->right != NULL) {
        pushLeft(obj, node->right);
    }

    return node->val;
}

bool bSTIteratorHasNext(BSTIterator* obj) {
    return obj->top >= 0;
}

void bSTIteratorFree(BSTIterator* obj) {
    free(obj);
}