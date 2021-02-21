def latest(scores):
    if len(scores) > 0:
        return scores[-1]

def personal_best(scores):
    if len(scores) > 0:
        best = 0
        for score in scores:
            if score > best:
                best = score
        return best

def personal_top_three(scores):
    return sorted(scores, reverse=True)[:3]
