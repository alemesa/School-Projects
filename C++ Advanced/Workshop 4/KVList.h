/*
OOP345
Workshop 4
Title    : Templates
Date     : 03/08/17
Author   : Alejandro Mesa
Student# : 038515151
Email    : amesasuarez@myseneca.ca
*/

#pragma once

#include <iostream>
#include <iomanip>
#include <string>

template <typename K, typename V, int N>

	class KVList {
		K k[N];
		V v[N];
		int count;
	public:
	KVList() : count(0) {

	}

	size_t size() const{
		return count;
	}

	const K& key(int i) const {
		return k[i];
	}

	const V& value(int i) const {
		return v[i];
	}



	int find(const K& kk)const {
		for(int i=0; i < count; i++) {
			if (kk==k[i]){
				return i;
			}
			}
		return -1;
	}

	KVList& add (const K& kk, const V& vv) {

		if (count < N) {
            v[count] = vv;
			k[count] = kk;
			count++;
		}

	return *this;

	}

	KVList& replace(int i, const K& kk, const V&vv) {
		if(i<count) {
			k[i]=kk;
			v[i]=vv;
		}
	return *this;
	}

	};
