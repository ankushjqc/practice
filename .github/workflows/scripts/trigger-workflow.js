const github = require('@actions/github');
const core = require('@actions/core');

async function run() {
  try {
    const token = core.getInput('GITHUB_TOKEN');
    const octokit = github.getOctokit(token);

    const { owner, repo } = github.context.repo;
    const workflowId = 'Name of Second Workflow';
    const ref = 'main';  // Adjust the branch if needed

    const response = await octokit.rest.actions.createWorkflowDispatch({
      owner,
      repo,
      workflow_id: workflowId,
      ref,
    });

    console.log('Workflow run triggered:', response.data);
  } catch (error) {
    core.setFailed(error.message);
  }
}

run();
