// #pragma GCC optimize('0fast')
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int n, b, m, t, counter = 0;
vi v, c;
vector<vector<int>> z(10, vector<int>(10, 0));

tuple< vector<vector<int>>, vector<vector<int>>> get_b_sized_vectors(const vector<int> & v, const int & n, const int & b )
{
    long long int N = pow(2, n);
    vector<vector<int>> int_power_set, index_power_set;

    for ( long long int i = 0; i < N; ++i )
    {
        vector<int> temp, index_temp;
        for( long long int j  = 0; j < n ; ++j ) if ( i & ( 1 << j) ) 
        {
            temp.push_back(v[j]);
            index_temp.push_back(j);
        }
        int_power_set.emplace_back(temp);
        index_power_set.emplace_back(index_temp);
    }

    vector<vector<int>> temp_vector, temp_index_vector;
    for ( int i = 0; i < int_power_set.size(); ++i ) 
        if ( int_power_set[i].size() == b ) {
            temp_vector.emplace_back(int_power_set[i]);
            temp_index_vector.emplace_back(index_power_set[i]);
        }

    return {temp_vector, temp_index_vector};
}

int main(int argc, char const *argv[])
{
    freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while ( scanf("%d %d", &n, &b) == 2 )
    {
        counter++;
        v.clear(); v.resize(n);
        for ( auto & value : v ) scanf("%d", &value);
        scanf("%d", &m);
        
        // Ending case here
        if ( m == 0 )
        {
            printf("Case Number  %d\n", counter );
            int sum = 0;
            for ( int i = 0; i < b; ++i ) sum += v[b];
            printf("Number Of Customers: %d\n", sum);
            printf("Locations recommended: ");
            for ( int i = 0 ; i < b ; ++i ) printf("%d ", i + 1);
            printf("\n\n");
            break;
        }

        c.clear(); c.resize(m); z.clear(); z.resize(m);
        for ( int i = 0; i < m ; ++i )
        {
            scanf("%d", &t);
            z[i].clear(); z[i].resize(t);
            for ( int j = 0 ; j < t ; ++j ) scanf("%d", &z[i][j]);
            scanf("%d", &c[i]);
        }

        // Process goes here
        auto[all_b_sized_vectors, index_power_set] = get_b_sized_vectors(v, n, b);

        long long int minn = -999999;
        vector<int> minn_vector; 
        for ( int i = 0; i < all_b_sized_vectors.size(); ++i )
        {
            long long int sum = 0 ;
            for( int j = 0 ; j < all_b_sized_vectors[i].size() ; ++j ) sum += all_b_sized_vectors[i][j];

            if ( sum >= minn ) 
            {
                minn = sum;
                minn_vector = index_power_set[i];
            }
        }

        // Output answer
        printf("Case Number  %d\n", counter);
        printf("Number Of Customers: %d\n", minn);
        printf("Locations recommended: ");
        for ( int i = 0 ; i < minn_vector.size() ; ++i ) printf("%d ", minn_vector[i] + 1);
        printf("\n\n");
    }

    return 0;
}