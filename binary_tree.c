/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 21:55:09 by jmorneau          #+#    #+#             */
/*   Updated: 2023/04/18 22:31:29 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct binary_tree
{
	struct binary_tree *left;
	struct binary_tree *right;
	int 				value;
}	tree;

tree *creatLeaf( int32_t v )
{
	tree *tmp = calloc(sizeof(tree), 1);
	tmp->value = v;

	return (tmp);
}

void insert_leaf(tree *root, tree *leaf)
{
	if (root->value > leaf->value)
	{
		if (root->left)
			insert_leaf(root->left, leaf);
		else
			root->left = leaf;
	}
	else if (root->value < leaf->value)
	{
		if (root->right)
			insert_leaf(root->right, leaf);
		else
			root->right = leaf;	
	}
	else
		free(leaf);
}

u_int32_t height_tree(tree *root, int res) // very long
{
	u_int32_t l = 0;
	u_int32_t r = 0;

	if (root->left)
		l = height_tree(root->left, res) + 1;
	if (root->right)
		r = height_tree(root->right, res) + 1;
	if (l >= r)
		return (res + l);
	return (res + r);
}


void print_tree(tree *root)
{
	printf("%d\n", root->value);

}

int main ( void )
{
	tree *root = { 0 };
	
	root = creatLeaf(20);
	insert_leaf(root, creatLeaf(10));
	insert_leaf(root, creatLeaf(11));
	insert_leaf(root, creatLeaf(9));
	insert_leaf(root, creatLeaf(8));




	insert_leaf(root, creatLeaf(30));
	

	printf("%d\n", height_tree(root, 0));
}