
class Solution:
    def accountsMerge(self, accounts: list[list[str]]) -> list[list[str]]:
        parent = list(range(len(accounts)))

        def find(x):
            if parent[x] != x:
                parent[x] = find(parent[x])
            return parent[x]

        def union(x, y):
            parent[find(x)] = find(y)

        email_to_id = {}

        for i, account in enumerate(accounts):
            for email in account[1:]:
                if email in email_to_id:
                    union(i, email_to_id[email])
                else:
                    email_to_id[email] = i

        groups = {}

        for email, i in email_to_id.items():
            root = find(i)
            groups.setdefault(root, []).append(email)

        result = []

        for i, emails in groups.items():
            result.append([accounts[i][0]] + sorted(emails))

        return result
