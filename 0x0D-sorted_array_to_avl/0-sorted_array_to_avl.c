#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avl_binary_trees.h"


/**
 * sort_data - ordenation of data set
 * @left:       left node
 * @right:      right node
 * @arr:        array of ints
 * @tree:       parent of current node
 * Return:      pointer to a node
 */

avl_t *sort_data(size_t left, size_t right, int *arr, avl_t *tree)
{
	avl_t *r_node = NULL, *l_node = NULL;
	size_t mid = (left + right) / 2;

	if (!tree)
		return (NULL);

	tree->n = arr[mid];
	if (mid > left && mid < right)
	{
		l_node = new_node();
		r_node = new_node();
		l_node->parent = tree;
		r_node->parent = tree;
		tree->left = sort_data(left, mid - 1, arr, l_node);
		tree->right = sort_data(mid + 1, right, arr, r_node);
	}
	else if (mid + 1 == right)
	{
		r_node = new_node();
		r_node->parent = tree;
		tree->right = r_node;
		r_node->n = arr[right];
	}
	return (tree);
}


/**
 * sorted_array_to_avl - creates an avl tree from an array
 * @array:      pointer to the array
 * @size:       size of the array
 * Return:      root node of AVL tree
 */

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL;

	if (!array || size < 1)
		return (NULL);

	root = new_node();
	root = sort_data(0, size - 1, array, root);

	return (root);
}

/**
 * new_node - creates a tree node
 * Return: pointer to the tree node
 */

avl_t *new_node()
{
	avl_t *new_tree = malloc(sizeof(avl_t));

	if (new_tree == NULL)
		exit(1);

	new_tree->left = new_tree->parent = new_tree->right = NULL;
	return (new_tree);
}